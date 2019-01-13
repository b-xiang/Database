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
		bool is(StatementType type) const;//isType�ļ�д

		size_t stringLength;  //SQL��䳤��
		std::vector<Expr*>* hints;
		virtual std::string execute(std::string username="default") = 0;//ִ�����
	private:
		StatementType type_;
	};
} // namespace hsql

#endif // SQLPARSER_SQLSTATEMENT_H
