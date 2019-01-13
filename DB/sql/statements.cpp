#include "statements.h"
#include "../Dict.h"
#include "../BlockMgr.h"
#include <iostream>
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
			if (db == nullptr)
				cout << "用户"<<user<<"没有表"<<schema << endl;
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
			dict->StoreClass(cls);
			
			break;
		}
		case hsql::kCreateTableFromTbl:
			break;
		case hsql::kCreateView:
			break;
		case hsql::kCreateSchema: {
			Database* db=dict->CreateDatabase();
			User* user = dict->GetUser(username);
			db->SetOwnerid(user->GetUserid());
			db->SetDatName(schema);
			db->SetOid(dict->DeliverOid());
			dict->StoreDatabase(db);
			delete user;
			delete db;
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
		switch (type)
		{
		case hsql::kInsertValues:
			break;
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
		switch (type)
		{
		case hsql::kShowColumns:
			break;
		case hsql::kShowTables:
			break;
		case hsql::kShowSchemas: {
			User* user=dict->GetUser(username);
			auto vec= dict->getDatabases(user);
			for (auto db : vec) {
				cout << db->datname << endl;
				delete db;
			}
			delete user;
			break;
		}
		default:
			break;
		}
		return "";
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
		return false;
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

} // namespace hsql
