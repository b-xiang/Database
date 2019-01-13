#ifndef SQLPARSER_EXECUTE_STATEMENT_H
#define SQLPARSER_EXECUTE_STATEMENT_H

#include "SQLStatement.h"


namespace hsql {

	// Represents SQL Execute statements.
	// Example: "EXECUTE ins_prep(100, "test", 2.3);"
	struct ExecuteStatement : SQLStatement {
		ExecuteStatement();
		virtual ~ExecuteStatement();
		virtual std::string execute(std::string username = "default");

		char* name;
		std::vector<Expr*>* parameters;
	};

} // namsepace hsql

#endif
