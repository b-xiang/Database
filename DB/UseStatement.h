#ifndef SQLPARSER_USE_STATEMENT_H
#define SQLPARSER_USE_STATEMENT_H

#include "SQLStatement.h"

// Note: Implementations of constructors and destructors can be found in statements.cpp.
namespace hsql {

	enum ShowType {
		kShowColumns,
		kShowTables,
		kShowSchemas
	};

	// Represents SQL SHOW statements.
	// Example "SHOW TABLES;"
	struct ShowStatement : SQLStatement {

		ShowStatement(ShowType type);
		virtual ~ShowStatement();
		virtual std::string execute(std::string username = "default");

		ShowType type;
		char* schema;
		char* name;
	};

} // namespace hsql
#endif
