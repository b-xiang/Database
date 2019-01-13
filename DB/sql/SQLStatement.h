#ifndef SQLPARSER_SQLSTATEMENT_H
#define SQLPARSER_SQLSTATEMENT_H

#include <vector>
#include <string>
#include "Expr.h"

namespace hsql {
	enum StatementType {
		kStmtError, // unused
		kStmtSelect,
		kStmtImport,
		kStmtInsert,
		kStmtUpdate,
		kStmtDelete,
		kStmtCreate,
		kStmtDrop,
		kStmtPrepare,
		kStmtExecute,
		kStmtExport,
		kStmtRename,
		kStmtAlter,
		kStmtShow
	};

	// Base struct for every SQL statement
	struct SQLStatement {
		SQLStatement(StatementType type);
		virtual ~SQLStatement();
		StatementType type() const;

		bool isType(StatementType type) const;
		bool is(StatementType type) const;//isTypeµÄ¼òÐ´

		size_t stringLength;  //SQLÓï¾ä³¤¶È
		std::vector<Expr*>* hints;
		virtual std::string execute(std::string username="default") = 0;//Ö´ÐÐÓï¾ä
	private:
		StatementType type_;
	};
} // namespace hsql

#endif // SQLPARSER_SQLSTATEMENT_H
