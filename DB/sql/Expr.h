#ifndef SQLPARSER_EXPR_H
#define SQLPARSER_EXPR_H

#include <stdlib.h>
#include <memory>
#include <vector>

namespace hsql {
	struct SelectStatement;

	char* substr(const char* source, int from, int to);

	enum ExprType {
		kExprLiteralFloat,
		kExprLiteralString,
		kExprLiteralInt,
		kExprLiteralNull,
		kExprStar,
		kExprParameter,
		kExprColumnRef,
		kExprFunctionRef,
		kExprOperator,
		kExprSelect,
		kExprHint,
		kExprArray,
		kExprArrayIndex,
		kExprDatetimeField,

		kExprDeleted,
		kExprUpdated
	};

	// Operator types.
	enum OperatorType {
		kOpNone,

		// 三目运算符
		kOpBetween,

		// 多元运算符
		kOpCase,
		kOpCaseListElement,  // `WHEN expr THEN expr`

		// 二元运算符
		kOpPlus,
		kOpMinus,
		kOpAsterisk,
		kOpSlash,
		kOpPercentage,
		kOpCaret,

		kOpEquals,
		kOpNotEquals,
		kOpLess,
		kOpLessEq,
		kOpGreater,
		kOpGreaterEq,
		kOpLike,
		kOpNotLike,
		kOpILike,
		kOpAnd,
		kOpOr,
		kOpIn,
		kOpConcat,

		// 单目运算符
		kOpNot,
		kOpUnaryMinus,
		kOpIsNull,
		kOpExists
	};

	enum DatetimeField {
		kDatetimeNone,
		kDatetimeSecond,
		kDatetimeMinute,
		kDatetimeHour,
		kDatetimeDay,
		kDatetimeMonth,
		kDatetimeYear,
	};

	typedef struct Expr Expr;

	// SQL元素类，可代表关键词、操作符及列名.
	// TODO: When destructing a placeholder expression, we might need to alter the placeholder_list.
	struct Expr {
		Expr(ExprType type);
		virtual ~Expr();

		ExprType type;

		// TODO: Replace expressions by list.
		Expr* expr;
		Expr* expr2;
		std::vector<Expr*>* exprList;
		SelectStatement* select;
		char* name;
		char* table;
		char* alias;
		double fval;
		int64_t ival;
		int64_t ival2;
		DatetimeField datetimeField;
		bool isBoolLiteral;

		OperatorType opType;
		bool distinct;

		bool isType(ExprType exprType) const;
		bool isLiteral() const;
		bool hasAlias() const;
		bool hasTable() const;
		const char* getName() const;

		//用来构造Expr
		static Expr* make(ExprType type);
		static Expr* makeOpUnary(OperatorType op, Expr* expr);
		static Expr* makeOpBinary(Expr* expr1, OperatorType op, Expr* expr2);
		static Expr* makeBetween(Expr* expr, Expr* left, Expr* right);
		static Expr* makeCaseList(Expr* caseListElement);
		static Expr* makeCaseListElement(Expr* when, Expr* then);
		static Expr* caseListAppend(Expr* caseList, Expr* caseListElement);
		static Expr* makeCase(Expr* expr, Expr* when, Expr* elseExpr);
		static Expr* makeLiteral(int64_t val);
		static Expr* makeLiteral(double val);
		static Expr* makeLiteral(char* val);
		static Expr* makeLiteral(const char* val);
		static Expr* makeLiteral(bool val);
		static Expr* makeNullLiteral();
		static Expr* makeColumnRef(char* name);
		static Expr* makeColumnRef(char* table, char* name);
		static Expr* makeStar(void);
		static Expr* makeStar(char* table);
		static Expr* makeFunctionRef(char* func_name, std::vector<Expr*>* exprList, bool distinct);
		static Expr* makeArray(std::vector<Expr*>* exprList);
		static Expr* makeArrayIndex(Expr* expr, int64_t index);
		static Expr* makeParameter(int id);
		static Expr* makeSelect(SelectStatement* select);
		static Expr* makeExists(SelectStatement* select);
		static Expr* makeInOperator(Expr* expr, std::vector<Expr*>* exprList);
		static Expr* makeInOperator(Expr* expr, SelectStatement* select);
		static Expr* makeExtract(DatetimeField datetimeField1, Expr* expr);
		static bool compare(Expr* val1, Expr*val2, OperatorType);
	};

	


	// Zero initializes an Expr object and assigns it to a space in the heap
	// For Hyrise we still had to put in the explicit NULL constructor
	// http://www.ex-parrot.com/~chris/random/initialise.html
	// Unused
#define ALLOC_EXPR(var, type)             \
    Expr* var;                            \
    do {                                  \
        Expr zero = {type};               \
        var = (Expr*)malloc(sizeof *var); \
        *var = zero;                      \
    } while (0);
#undef ALLOC_EXPR

}  // namespace hsql

#endif
