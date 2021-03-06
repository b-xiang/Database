#include "statements.h"
#include "../Dict.h"
#include "../BlockMgr.h"
#include "../IdxMgr.h"
#include "../Block.h"
#include "../Logger.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace hsql {


	std::vector<Expr*> select(std::vector<Expr*> ori, Expr* whereClause, std::vector<Attribute*> attrs);
	std::vector<Expr*> project(std::vector<Expr*> ori, std::vector<Expr*> selectList, std::vector<Attribute*> attrs);
	std::vector<Expr*> intersectExprs(std::vector<Expr*> left, std::vector<Expr*> right);
	std::vector<Expr*> unionExprs(std::vector<Expr*> left, std::vector<Expr*> right);


	// ColumnDefinition
	ColumnDefinition::ColumnDefinition(char* name, ColumnType type, bool nullable) :
		name(name),
		type(type),
		nullable(nullable) {};

	ColumnDefinition::~ColumnDefinition() {
		free(name);
	}

	ColumnType::ColumnType(DataType data_type, int64_t length) :
		data_type(data_type),
		length(length) {};

	bool operator==(const ColumnType& lhs, const ColumnType& rhs) {
		if (lhs.data_type != rhs.data_type) return false;
		if (lhs.data_type == DataType::VARCHAR || lhs.data_type == DataType::CHAR) {
			return lhs.length == rhs.length;
		}
		return true;
	}

	bool operator!=(const ColumnType& lhs, const ColumnType& rhs) {
		return !(lhs == rhs);
	}

	std::ostream& operator<<(std::ostream& stream, const ColumnType& column_type) {
		switch (column_type.data_type) {
		case DataType::UNKNOWN:
			stream << "UNKNOWN";
			break;
		case DataType::INT:
			stream << "INT";
			break;
		case DataType::LONG:
			stream << "LONG";
			break;
		case DataType::FLOAT:
			stream << "FLOAT";
			break;
		case DataType::DOUBLE:
			stream << "DOUBLE";
			break;
		case DataType::CHAR:
			stream << "CHAR(" << column_type.length << ")";
			break;
		case DataType::VARCHAR:
			stream << "VARCHAR(" << column_type.length << ")";
			break;
		case DataType::TEXT:
			stream << "TEXT";
			break;
		}
		return stream;
	}


	// CreateStatemnet
	CreateStatement::CreateStatement(CreateType type) :
		SQLStatement(kStmtCreate),
		type(type),
		ifNotExists(false),
		filePath(nullptr),
		schema(nullptr),
		tableName(nullptr),
		columns(nullptr),
		onWhich(nullptr),
		viewColumns(nullptr),
		select(nullptr) {};

	CreateStatement::~CreateStatement() {
		free(filePath);
		free(schema);
		free(tableName);
		delete select;

		if (columns != nullptr) {
			for (ColumnDefinition* def : *columns) {
				delete def;
			}
			delete columns;
		}

		if (viewColumns != nullptr) {
			for (char* column : *viewColumns) {
				free(column);
			}
			delete viewColumns;
		}
	}

	string CreateStatement::execute(string username)
	{
		Dict* dict = Dict::getInstance();
		switch (type)
		{
		case hsql::kCreateTable: {
			User* user = dict->GetUser(username);
			Database* db = dict->GetDatabase(user,schema);
			if (db == nullptr) {
				delete user;
				return "Error: Unknow database "+string(schema)+"\n";
			}	
			Class* cls=dict->CreateClass();
			cls->oid = dict->DeliverOid();
			cls->databaseid = db->GetOid();
			cls->relname = tableName;
			BlockMgr*mgr = BlockMgr::getInstance();
			string fileid=mgr->allocFile();
			string blockid = mgr->allocBlock(fileid, table);
			cls->relfileid = fileid;
			cls->relblockid = blockid;
			cls->relkind = 'r';
			cls->relnatts = columns->size();
			dict->StoreClass(cls);
			for (int i = 0; i < columns->size(); i++) {
				Attribute* attr = dict->CreateAttribute();
				attr->oid = dict->DeliverOid();
				attr->attnum = i;
				attr->name = (*columns)[i]->name;
				attr->relid = cls->oid;
				attr->notnull = (*columns)[i]->nullable;
				if ((*columns)[i]->type.data_type == DataType::INT|| (*columns)[i]->type.data_type == DataType::LONG) {
					attr->type = kExprLiteralInt;
				}
				else if ((*columns)[i]->type.data_type == DataType::FLOAT || (*columns)[i]->type.data_type == DataType::DOUBLE) {
					attr->type = kExprLiteralFloat;
				}
				else if ((*columns)[i]->type.data_type == DataType::VARCHAR || (*columns)[i]->type.data_type == DataType::CHAR) {
					attr->type = kExprLiteralString;
					attr->varcharlen = (*columns)[i]->type.length;
				}
				else if ((*columns)[i]->type.data_type == DataType::TEXT) {
					attr->type = kExprLiteralString;
				}
				dict->StoreAttribute(attr);
				delete attr;
			}
			Logger::getLogger()->logToFile("Create table " + string(schema));
			delete user;
			delete db;
			delete cls;
			break;
		}
		case hsql::kCreateTableFromTbl:
			break;
		case hsql::kCreateView:
			break;
		case hsql::kCreateSchema: {
			User* user = dict->GetUser(username);
			Database* db = dict->GetDatabase(user, schema);
			if (db != nullptr)
			{
				delete user;
				delete db;
				return "Error! Can not create database " + string(schema) + " :Databased existed.\n";
			}
			db=dict->CreateDatabase();
			db->SetOwnerid(user->GetUserid());
			db->SetDatName(schema);
			db->SetOid(dict->DeliverOid());
			dict->StoreDatabase(db);

			Logger::getLogger()->logToFile("Create schema " + string(schema));
			delete user;
			delete db;
			break;
		}
		case hsql::kCreateIndex: {
			User* user = dict->GetUser(username);
			string _schema;
			if (schema == nullptr)
				if (Dict::getCurSchema() != "")
					_schema = Dict::getCurSchema();
				else {
					delete user;
					return "Error! No database selected\n";
				}
			else
				_schema = schema;
			Database* db = dict->GetDatabase(user, _schema);
			Class* cls = dict->GetClass(db, tableName);
			if (cls == nullptr) {
				delete user;
				delete db;
				delete cls;
				return "Error: Unknow table " + string(tableName) + "\n";
			}
			vector<Attribute*> attrs = dict->GetAttribute(cls);
			for (auto attr : attrs) {
				if (attr->name == onWhich) {
					if (attr->IsPkey()) {
						delete user;
						delete db;
						delete cls;
						for (auto attr : attrs) {
							delete attr;
						}
						return "Error: Index on " + string(onWhich) + " has been set up";
					}
					else {
						attr->SetPkey(true);
						IdxMgr* mgr=IdxMgr::getInstance();
						mgr->createIdx(attr->oid);
						dict->UpdateAttribute(attr);
					}
				}
			}
			delete user;
			delete db;
			delete cls;
			for (auto attr : attrs) {
				delete attr;
			}
			//Logger::getLogger()->logToFile("Create index on " + string(schema)+"."+ string(tableName));
			break;
		}
		default:
			break;
		}

		return "";
	}

	// DeleteStatement
	DeleteStatement::DeleteStatement() :
		SQLStatement(kStmtDelete),
		schema(nullptr),
		tableName(nullptr),
		expr(nullptr) {};

	DeleteStatement::~DeleteStatement() {
		free(schema);
		free(tableName);
		delete expr;
	}

	string DeleteStatement::execute(string username)
	{
		stringstream ss;
		Dict* dict = Dict::getInstance();
		User* user = dict->GetUser(username);
		string _schema;
		if (schema == nullptr)
			if (Dict::getCurSchema() != "")
				_schema = Dict::getCurSchema();
			else {
				delete user;
				return "Error! No database selected\n";
			}
		else
			_schema = schema;
		Database* db = dict->GetDatabase(user, _schema);
		Class* cls = dict->GetClass(db, tableName);
		if (cls == nullptr) {
			delete user;
			delete db;
			delete cls;
			return "Error: Unknow table " + string(tableName) + "\n";
		}
		vector<Attribute*> attrs = dict->GetAttribute(cls);
		vector<Expr*> exprs;
		vector<bool> visit;

		vector<string> rids;
		vector<Expr*> records;
		map<Expr*, string> recordRidMap;
		vector<bool> haveIdx;
		
		for (int i = 0; i < attrs.size();i++) {
			bool hasIdx = false;
			if (attrs[i]->IsPkey()) {
				hasIdx = true;
				rids = IdxMgr::getInstance()->getRowids(attrs[i]->oid);
				records = BlockMgr::getInstance()->multipleGet(rids);
				for (int i = 0; i < rids.size(); i++) {
					recordRidMap[records[i]] = rids[i];
				}
			}
			haveIdx.push_back(hasIdx);
		}
		bool flag = false;
		for (auto b : haveIdx) {
			if (b == true) {
				flag = true;
			}
		}
		if (!flag) {
			return "Error! No index";
		}
			
		vector<Expr*>res = select(records, expr, attrs);
		
		for (int i = 0; i < attrs.size(); i++) {
			if (attrs[i]->IsPkey()) {
				for (auto r : res) {
					IdxMgr::getInstance()->removeRecord(attrs[i]->oid,(*r->exprList)[i]);
				}
			}
		}

		vector<string> tobeDeleted;
		for (auto r : res) {
			tobeDeleted.push_back(recordRidMap[r]);
		}
		BlockMgr::getInstance()->multiRemove(tobeDeleted);

		delete user;
		delete db;
		delete cls;
		for (auto attr : attrs) {
			delete attr;
		}
		Logger::getLogger()->logToFile("Delete from " + string(_schema) + "." + string(tableName));
		return "";
	}

	// DropStatament
	DropStatement::DropStatement(DropType type) :
		SQLStatement(kStmtDrop),
		type(type),
		schema(nullptr),
		name(nullptr) {}

	DropStatement::~DropStatement() {
		free(schema);
		free(name);
	}

	string DropStatement::execute(string username)
	{
		switch (type)
		{
		case hsql::kDropTable:
			break;
		case hsql::kDropSchema:
			break;
		case hsql::kDropIndex:
			break;
		case hsql::kDropView:
			break;
		case hsql::kDropPreparedStatement:
			break;
		default:
			break;
		}
		return "";
	}

	// ExecuteStatement
	ExecuteStatement::ExecuteStatement() :
		SQLStatement(kStmtExecute),
		name(nullptr),
		parameters(nullptr) {}

	ExecuteStatement::~ExecuteStatement() {
		free(name);

		if (parameters != nullptr) {
			for (Expr* param : *parameters) {
				delete param;
			}
			delete parameters;
		}
	}

	string ExecuteStatement::execute(string username)
	{
		return false;
	}

	// ImportStatement
	ImportStatement::ImportStatement(ImportType type) :
		SQLStatement(kStmtImport),
		type(type),
		filePath(nullptr),
		schema(nullptr),
		tableName(nullptr) {};

	ImportStatement::~ImportStatement() {
		free(filePath);
		free(schema);
		free(tableName);
	}

	string ImportStatement::execute(string username)
	{
		switch (type)
		{
		case hsql::kImportCSV:
			break;
		case hsql::kImportTbl:
			break;
		default:
			break;
		}
		return "";
	}

	// InsertStatement
	InsertStatement::InsertStatement(InsertType type) :
		SQLStatement(kStmtInsert),
		type(type),
		schema(nullptr),
		tableName(nullptr),
		columns(nullptr),
		values(nullptr),
		select(nullptr) {}

	InsertStatement::~InsertStatement() {
		free(schema);
		free(tableName);
		delete select;

		if (columns != nullptr) {
			for (char* column : *columns) {
				free(column);
			}
			delete columns;
		}

		if (values != nullptr) {
			for (Expr* expr : *values) {
				delete expr;
			}
			delete values;
		}
	}

	string InsertStatement::execute(string username)
	{
		
		Dict* dict = Dict::getInstance();
		switch (type)
		{
		case hsql::kInsertValues: {
			User* user = dict->GetUser(username);
			string _schema;
			if (schema == nullptr)
				if (Dict::getCurSchema() != "")
					_schema = Dict::getCurSchema();
				else {
					delete user;
					return "Error! No database selected\n";
				}
			else
				_schema = schema;
			Database* db = dict->GetDatabase(user, _schema);
			Class* cls = dict->GetClass(db, tableName);
			if (cls == nullptr) {
				delete user;
				delete db;
				delete cls;
				return "Error: Unknown table " + string(tableName) + "\n";
			}
			vector<Attribute*> attrs = dict->GetAttribute(cls);
			vector<Expr*> exprs;
			vector<bool> visit;
			if (columns != nullptr) {
				for (auto attr : attrs) {
					bool found = false;
					for (int i = 0; i < (*columns).size(); i++) {
						if (strcmp(attr->name.c_str(), (*columns)[i]) == 0) {
							if (attr->type == (*values)[i]->type) {
								if (attr->type == kExprLiteralString)
									exprs.push_back(Expr::makeLiteral(string((*values)[i]->name).substr(0, attr->varcharlen).c_str()));
								else
									exprs.push_back((*values)[i]);
							}
							else {
								delete user, db, cls;
								for (auto attr : attrs) {
									delete attr;
								}
								return "Error: Unexpected data type\n";
							}
							found = true;
						}
					}
					visit.push_back(found);
					if (!found) {//���ǿ�
						if (attr->IsNotNull()) {
							delete user, db, cls;
							for (auto attr : attrs) {
								delete attr;
							}
							return "Error: Attribute " + attr->name + " can not be null\n";
						}
						else {
							exprs.push_back(Expr::makeNullLiteral());
						}
					}
				}
			}
			else {
				for (int i = 0; i < attrs.size();i++) {
					visit.push_back(true);
					if (attrs[i]->type == (*values)[i]->type) {
						if (attrs[i]->type == kExprLiteralString)
							exprs.push_back(Expr::makeLiteral(string((*values)[i]->name).substr(0, attrs[i]->varcharlen).c_str()));
						else
							exprs.push_back((*values)[i]);
					}
					else if (attrs[i]->type==kExprLiteralFloat&& (*values)[i]->type==kExprLiteralInt) {
						exprs.push_back(Expr::makeLiteral((double)(*values)[i]->ival));
					}
					else {
						delete user, db, cls;
						for (auto attr : attrs) {
							delete attr;
						}
						return "Error: Unexpected data type\n";
					}	
				}
			}
			
			Expr* final = Expr::makeArray(&exprs);
			Block* blk=BlockMgr::getInstance()->getLastAvailableBlock(cls->relfileid);
			string rid=blk->put(final);
			
			for (int i = 0; i < attrs.size();i++) {
				if (visit[i]&&attrs[i]->IsPkey()) {
					IdxMgr::getInstance()->addRecord(attrs[i]->oid,exprs[i],rid);
				}
			}

			delete user;
			delete db;
			delete cls;
			for (auto attr : attrs) {
				delete attr;
			}
			break;
		}
		case hsql::kInsertSelect:
			break;
		default:
			break;
		}
		//Logger::getLogger()->logToFile("Insert into " + string(schema) + "." + string(tableName));
		return "";
	}

	// ShowStatament
	ShowStatement::ShowStatement(ShowType type) :
		SQLStatement(kStmtShow),
		type(type),
		schema(nullptr),
		name(nullptr) {}

	ShowStatement::~ShowStatement() {
		free(schema);
		free(name);
	}

	string ShowStatement::execute(string username)
	{
		Dict* dict = Dict::getInstance();
		stringstream ss;
		switch (type)
		{
		case hsql::kShowColumns: {
			if (Dict::getCurSchema() == "") {
				return "Error: No database selected\n";
			}
			auto user = dict->GetUser(username);
			auto db = dict->GetDatabase(user, Dict::getCurSchema());
			auto cls = dict->GetClass(db, name);
			if (cls == nullptr) {
				delete user;
				delete db;
				return "Error: Unknown table " + string(name) + "\n";
			}
			auto attrs = dict->GetAttribute(cls);
			for (auto attr : attrs) {
				ss << attr->name << endl;
			}
			delete user;
			delete db;
			delete cls;
			for (auto attr : attrs) {
				delete attr;
			}
			break;
		}
		case hsql::kShowTables: {
			if (Dict::getCurSchema() == "") {
				return "Error: No database selected\n";
			}
			auto user = dict->GetUser(username);
			auto db = dict->GetDatabase(user, Dict::getCurSchema());
			auto clses = dict->getClasses(db);
			for (auto cls : clses) {
				ss << cls->relname << endl;
			}
			for (auto cls : clses) {
				delete cls;
			}
			break;
		}
		case hsql::kShowSchemas: {
			User* user=dict->GetUser(username);
			auto vec= dict->getDatabases(user);
			for (auto db : vec) {
				ss<<db->datname << endl;
			}
			delete user;
			for (auto v : vec) {
				delete v;
			}
			break;
		}
		default:
			break;
		}
		return ss.str();
	}

	// SelectStatement.h

	// OrderDescription
	OrderDescription::OrderDescription(OrderType type, Expr* expr) :
		type(type),
		expr(expr) {}

	OrderDescription::~OrderDescription() {
		delete expr;
	}

	// LimitDescription
	LimitDescription::LimitDescription(int64_t limit, int64_t offset) :
		limit(limit >= 0 ? limit : kNoLimit),
		offset(offset > 0 ? offset : kNoOffset) {}

	// GroypByDescription
	GroupByDescription::GroupByDescription() :
		columns(nullptr),
		having(nullptr) {}

	GroupByDescription::~GroupByDescription() {
		delete having;

		if (columns != nullptr) {
			for (Expr* expr : *columns) {
				delete expr;
			}
			delete columns;
		}
	}

	// SelectStatement
	SelectStatement::SelectStatement() :
		SQLStatement(kStmtSelect),
		fromTable(nullptr),
		selectDistinct(false),
		selectList(nullptr),
		whereClause(nullptr),
		groupBy(nullptr),
		unionSelect(nullptr),
		order(nullptr),
		limit(nullptr) {};

	SelectStatement::~SelectStatement() {
		delete fromTable;
		delete whereClause;
		delete groupBy;
		delete unionSelect;
		delete limit;

		// Delete each element in the select list.
		if (selectList != nullptr) {
			for (Expr* expr : *selectList) {
				delete expr;
			}
			delete selectList;
		}

		if (order != nullptr) {
			for (OrderDescription* desc : *order) {
				delete desc;
			}
			delete order;
		}
	}

	string SelectStatement::execute(string username)
	{
		stringstream ss;
		vector<Expr*> res;
		Dict* dict = Dict::getInstance();
		User* user = dict->GetUser(username);
		string _schema;
		if (fromTable->schema == nullptr)
			if (Dict::getCurSchema() != "")
				_schema = Dict::getCurSchema();
			else {
				delete user;
				return "Error! No database selected\n";
			}
		else
			_schema = fromTable->schema;
		Database* db = dict->GetDatabase(user, _schema);
		Class* cls = dict->GetClass(db, fromTable->name);
		if (cls == nullptr) {
			delete user;
			delete db;
			delete cls;
			return "Error: Unknow table " + string(fromTable->name) + "\n";
		}
		vector<Attribute*> attrs = dict->GetAttribute(cls);
		vector<Expr*> exprs;
		vector<bool> visit;
		
		bool hasIdx=false;
		for (auto attr : attrs) {
			if (attr->IsPkey()) {
				hasIdx = true;
				vector<string> rids;
				if (whereClause!=nullptr&&whereClause->expr->name == attr->name) {
					COMPARE_OPERATOR cp;
					if (whereClause->opType == kOpEquals)
						cp = EQ;
					else if (whereClause->opType == kOpGreater)
						cp = BT;
					else if (whereClause->opType == kOpGreaterEq)
						cp = BE;
					else if (whereClause->opType == kOpLess)
						cp = LT;
					else if (whereClause->opType == kOpLessEq)
						cp = LE;
					rids = IdxMgr::getInstance()->getRowids(attr->oid,whereClause->expr2,cp);
				}
				else {
					rids = IdxMgr::getInstance()->getRowids(attr->oid);
				}
				auto r = BlockMgr::getInstance()->multipleGet(rids);
				res.insert(res.begin(),r.begin(),r.end());
				break;
			}
		}
		if (!hasIdx) {
			Block*curblk = BlockMgr::getInstance()->getBlock(cls->relfileid, cls->relblockid);
			do {
				auto r=curblk->getFromFrontToEnd();
				res.insert(res.begin(), r.begin(), r.end());
				curblk = BlockMgr::getInstance()->getBlock(cls->relfileid, curblk->GetNextblockid());
			} while (curblk->GetNextblockid() == "");
		}
		
		res=select(res, whereClause,attrs);
		res=project(res,*selectList,attrs);

		//display

		if ((*selectList)[0]->type == kExprStar) {
			for (auto attr : attrs) {
				ss << attr->name << "\t";
			}
			ss << endl;
		}
		else {
			for (auto item : (*selectList)) {
				ss << item->name << "\t";
			}
			ss << endl;
		}
		for (auto r : res) {
			for (auto item : (*r->exprList)) {
				if (item->type == kExprLiteralInt)
					ss << item->ival << "\t";
				else if (item->type == kExprLiteralFloat)
					ss << item->fval << "\t";
				else if (item->type == kExprLiteralString)
					ss << item->name << "\t";
				else if (item->type == kExprLiteralNull)
					ss << "NULL" << "\t";
			}
			ss << endl;
		}

		delete user;
		delete db;
		delete cls;
		for (auto attr : attrs) {
			delete attr;
		}
		return ss.str();
	}


	std::vector<Expr*> select(std::vector<Expr*> ori, Expr * whereClause, std::vector<Attribute*> attrs)
	{
		vector<Expr*> res;
		if(whereClause==nullptr)
			return ori;
		else {
			if (whereClause->isBoolLiteral&& whereClause->ival == 1) {
				return ori;
			}
			else if (whereClause->opType == kOpAnd) {
				return intersectExprs(select(ori, whereClause->expr, attrs), select(ori, whereClause->expr,attrs));
			}
			else if (whereClause->opType == kOpOr) {
				return unionExprs(select(ori, whereClause->expr, attrs), select(ori, whereClause->expr2,attrs));
			}
			else {
				Expr* tableref=whereClause->expr;
				int idx = -1;
				for (int i = 0; i < attrs.size(); i++) {
					if (tableref->name == attrs[i]->name) {
						idx = i;
					}
				}
				if (idx == -1) {
					return res;
				}
				for (auto item : ori) {
					if (Expr::compare((*item->exprList)[idx], whereClause->expr2, whereClause->opType)){
						res.push_back(item);
					}
				}
			}
		}
		return res;
	}

	std::vector<Expr*> project(std::vector<Expr*> ori, std::vector<Expr*> selectList, std::vector<Attribute*> attrs)
	{
		vector<Expr*> res;
		if (selectList.size() == 1 && selectList[0]->type == kExprStar)
			return ori;
		else {
			vector<bool> show;
			for (auto item : attrs) {
				bool found = false;
				for (auto s : selectList) {
					if (s->name == item->name)
					{
						found = true;
						break;
					}
				}
				show.push_back(found);
			}
			for (auto item : ori) {
				vector<Expr*>* tmp=new vector<Expr*>;
				for (int i = 0; i < show.size(); i++) {
					if (show[i])
						tmp->push_back((*item->exprList)[i]);
				}
				res.push_back(Expr::makeArray(tmp));
			}
		}
		return res;
	}

	std::vector<Expr*> intersectExprs(std::vector<Expr*> left, std::vector<Expr*> right)
	{
		vector<Expr*> res;
		for (int i = 0; i < left.size();i++) {
			bool found = false;
			for (int j = 0; j < right.size(); j++) {
				if (left[i]==right[j])
					found = true;
			}
			if (found) {
				res.push_back(left[i]);
			}
		}
		return res;
	}

	std::vector<Expr*> unionExprs(std::vector<Expr*> left, std::vector<Expr*> right)
	{
		vector<Expr*> res;
		res.insert(res.end(), right.begin(), right.end());
		for (int i = 0; i < left.size(); i++) {
			bool found = false;
			for (int j = 0; j < right.size(); j++) {
				if (left[i] == right[j])
					found = true;
			}
			if (!found) {
				res.push_back(left[i]);
			}
		}
		return res;
	}



	// UpdateStatement
	UpdateStatement::UpdateStatement() :
		SQLStatement(kStmtUpdate),
		table(nullptr),
		updates(nullptr),
		where(nullptr) {}

	UpdateStatement::~UpdateStatement() {
		delete table;
		delete where;

		if (updates != nullptr) {
			for (UpdateClause* update : *updates) {
				free(update->column);
				delete update->value;
				delete update;
			}
			delete updates;
		}
	}

	string UpdateStatement::execute(string username)
	{
		stringstream ss;
		Dict* dict = Dict::getInstance();
		User* user = dict->GetUser(username);
		string _schema;
		if (table->schema == nullptr)
			if (Dict::getCurSchema() != "")
				_schema = Dict::getCurSchema();
			else {
				delete user;
				return "Error! No database selected\n";
			}
		else
			_schema = table->schema;
		Database* db = dict->GetDatabase(user, _schema);
		Class* cls = dict->GetClass(db, table->name);
		if (cls == nullptr) {
			delete user;
			delete db;
			delete cls;
			return "Error: Unknow table " + string(table->name) + "\n";
		}
		vector<Attribute*> attrs = dict->GetAttribute(cls);
		vector<Expr*> exprs;
		vector<bool> visit;

		vector<string> rids;
		vector<Expr*> records;
		map<Expr*, string> recordRidMap;
		vector<bool> haveIdx;

		for (int i = 0; i < attrs.size(); i++) {
			bool hasIdx = false;
			if (attrs[i]->IsPkey()) {
				hasIdx = true;
				if (where != nullptr&& where->type!=kExprLiteralInt&&where->expr->name == attrs[i]->name) {
					COMPARE_OPERATOR cp;
					if (where->opType == kOpEquals)
						cp = EQ;
					else if (where->opType == kOpGreater)
						cp = BT;
					else if (where->opType == kOpGreaterEq)
						cp = BE;
					else if (where->opType == kOpLess)
						cp = LT;
					else if (where->opType == kOpLessEq)
						cp = LE;
					rids = IdxMgr::getInstance()->getRowids(attrs[i]->oid, where->expr2, cp);
				}
				else {
					rids = IdxMgr::getInstance()->getRowids(attrs[i]->oid);
				}
				records = BlockMgr::getInstance()->multipleGet(rids);
				for (int i = 0; i < rids.size(); i++) {
					recordRidMap[records[i]] = rids[i];
				}
			}
			haveIdx.push_back(hasIdx);
		}
		bool flag = false;
		for (auto b : haveIdx) {
			if (b == true) {
				flag = true;
			}
		}
		if (!flag) {
			return "Error! No index";
		}

		vector<Expr*>res = select(records, where, attrs);
		vector<Expr*>tmp;
		vector<string> tobeUpdated;
		for (auto r : res) {
			tobeUpdated.push_back(recordRidMap[r]);
		}
		for (auto item : *updates) {
			if (item->value->type != kExprColumnRef) {
				int idx=-1;
				for (int i = 0; i < attrs.size();i++) {
					if (attrs[i]->name == item->column) {
						idx = i;
						break;
					}
				}
				if (idx == -1) {
					delete user;
					delete db;
					delete cls;
					for (auto attr : attrs) {
						delete attr;
					}
					return "Error! No attribute named" + string(item->column);
				}
				else {
					for (auto i : res) {
						vector<Expr*>* s=new vector<Expr*>;
						for (int j = 0; j < (*i->exprList).size();j++) {
							if (j != idx) {
								s->push_back((*i->exprList)[j]);
							}
							else {
								s->push_back(item->value);
							}
						}
						tmp.push_back(Expr::makeArray(s));
					}
				}
			}
			else {
				int idx1 = -1;
				for (int i = 0; i < attrs.size(); i++) {
					if (attrs[i]->name == item->column) {
						idx1 = i;
						break;
					}
				}
				int idx2 = -1;
				for (int i = 0; i < attrs.size(); i++) {
					if (attrs[i]->name == item->value->name) {
						idx2 = i;
						break;
					}
				}
				if (idx1 == -1||idx2==-1) {
					delete user;
					delete db;
					delete cls;
					for (auto attr : attrs) {
						delete attr;
					}
					return "Error! No attribute named" + string(item->column);
				}
				else {
					for (auto i : res) {
						vector<Expr*>* s = new vector<Expr*>;
						for (int j = 0; j < (*i->exprList).size(); j++) {
							if (j != idx1) {
								s->push_back((*i->exprList)[j]);
							}
							else {
								s->push_back((*i->exprList)[idx2]);
							}
						}
						tmp.push_back(Expr::makeArray(s));
					}
				}
			}
		}
		BlockMgr::getInstance()->multipleUpdate(tobeUpdated,tmp);

		Logger::getLogger()->logToFile("Update " + string(_schema) + "." + string(table->name));
		delete user;
		delete db;
		delete cls;
		for (auto attr : attrs) {
			delete attr;
		}
		
		return "";
	}

	// PrepareStatement
	PrepareStatement::PrepareStatement() :
		SQLStatement(kStmtPrepare),
		name(nullptr),
		query(nullptr) {}

	PrepareStatement::~PrepareStatement() {
		free(name);
		free(query);
	}
	string PrepareStatement::execute(string username)
	{
		return false;
	}

	// Alias
	Alias::Alias(char* name, std::vector<char*>* columns) :
		name(name),
		columns(columns) {}

	Alias::~Alias() {
		free(name);
		if (columns) {
			for (char* column : *columns) {
				free(column);
			}
			delete columns;
		}
	}

	// TableRef
	TableRef::TableRef(TableRefType type) :
		type(type),
		schema(nullptr),
		name(nullptr),
		alias(nullptr),
		select(nullptr),
		list(nullptr),
		join(nullptr) {}

	TableRef::~TableRef() {
		free(schema);
		free(name);

		delete select;
		delete join;
		delete alias;

		if (list != nullptr) {
			for (TableRef* table : *list) {
				delete table;
			}
			delete list;
		}
	}

	bool TableRef::hasSchema() const {
		return schema != nullptr;
	}

	const char* TableRef::getName() const {
		if (alias) return alias->name;
		else return name;
	}

	// JoinDefinition
	JoinDefinition::JoinDefinition() :
		left(nullptr),
		right(nullptr),
		condition(nullptr),
		type(kJoinInner) {}

	JoinDefinition::~JoinDefinition() {
		delete left;
		delete right;
		delete condition;
	}

	hsql::UseStatement::UseStatement():
		SQLStatement(kStmtUse)
	{
	}
	string hsql::UseStatement::execute(string username)
	{
		auto dict=Dict::getInstance();
		auto user = dict->GetUser(username);
		auto db = dict->GetDatabase(user, schema);
		if (db != nullptr) {
			Dict::setCurSchema(schema);
			Logger::getLogger()->logToFile("Change default database to " + string(schema));
			delete user;
			delete db;
			return "Database changed\n";
		}
		else {
			delete user;
			return "Unknow database '" +string( schema) + "'";
		}
	}


} // namespace hsql
