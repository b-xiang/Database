#include "statements.h"
#include "../Dict.h"
#include "../BlockMgr.h"
#include "../IdxMgr.h"
#include "../Block.h"
#include <iostream>
#include <sstream>
using namespace std;

namespace hsql {

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
		return false;
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
				return "Error: Unknow table " + string(tableName) + "\n";
			}
			vector<Attribute*> attrs = dict->GetAttribute(cls);
			vector<Expr*> exprs;
			vector<bool> visit;
			for (auto attr : attrs) {
				bool found = false;
				for(int i=0;i<(*columns).size();i++){
					if (strcmp(attr->name.c_str(),(*columns)[i])==0) {
						if(attr->type== (*values)[i]->type)
							exprs.push_back((*values)[i]);
						else {
							delete user, db, cls;
							for (auto attr : attrs) {
								delete attr;
							}
							for (auto expr : exprs) {
								delete expr;
							}
							return "Error: Unexpected data type\n";
						}
						found = true;
					}
				}
				visit.push_back(found);
				if (!found) {//¼ì²â·Ç¿Õ
					if (attr->IsNotNull()) {
						delete user, db, cls;
						for (auto attr : attrs) {
							delete attr;
						}
						for (auto expr : exprs) {
							delete expr;
						}
						return "Error: Attribute "+attr->name+" can not be null\n";
					}
					else {
						exprs.push_back(Expr::makeNullLiteral());
					}
				}
				if (found) {

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
		if (selectList->size() == 1 && (*selectList)[0]->type == kExprStar) {
			for (auto attr : attrs) {
				if (attr->IsPkey()) {
					auto rids=IdxMgr::getInstance()->getRowids(attr->oid);
					auto r = BlockMgr::getInstance()->multipleGet(rids);
					res.insert(res.begin(),r.begin(),r.end());
					break;
				}
			}
		}
		else {

		}


		//display
		if ((*selectList)[0]->type == kExprStar) {
			for (auto attr : attrs) {
				ss << attr->name << "\t";
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
