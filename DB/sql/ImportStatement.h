#ifndef SQLPARSER_IMPORT_STATEMENT_H
#define SQLPARSER_IMPORT_STATEMENT_H

#include "SQLStatement.h"

namespace hsql {
	enum ImportType {
		kImportCSV,
		kImportTbl, // Hyrise file format
	};

	// Represents SQL Import statements.
	struct ImportStatement : SQLStatement {
		ImportStatement(ImportType type);
		virtual ~ImportStatement();
		virtual std::string execute(std::string username = "default");

		ImportType type;
		char* filePath;
		char* schema;
		char* tableName;
	};

} // namespace hsql

#endif
