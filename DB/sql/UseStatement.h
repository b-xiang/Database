#ifndef SQLPARSER_USE_STATEMENT_H
#define SQLPARSER_USE_STATEMENT_H

#include "SQLStatement.h"

// Note: Implementations of constructors and destructors can be found in statements.cpp.
namespace hsql {

	struct UseStatement : SQLStatement {

		UseStatement();
		virtual ~UseStatement() {}
		virtual std::string execute(std::string username = "default");
		char* schema;
	};

} // namespace hsql
#endif
