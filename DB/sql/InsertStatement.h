#ifndef SQLPARSER_INSERT_STATEMENT_H
#define SQLPARSER_INSERT_STATEMENT_H

#include "SQLStatement.h"
#include "SelectStatement.h"

namespace hsql {
	enum InsertType {
		kInsertValues,
		kInsertSelect
	};

	struct InsertStatement : SQLStatement {
		InsertStatement(InsertType type);
		virtual ~InsertStatement();
		virtual std::string execute(std::string username = "default");

		InsertType type;
		char* schema;
		char* tableName;
		std::vector<char*>* columns;
		std::vector<Expr*>* values;
		SelectStatement* select;
	};

} // namsepace hsql

#endif
