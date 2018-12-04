#ifndef IDX_MRG_H
#define IDX_MRG_H
#include <string>
#include <vector>
#include "sql/Expr.h"
using namespace std;
using namespace hsql;

class BPlusTree;


typedef struct col_idx {//列名和对应的B+树的根
	string colRef;
	BPlusTree* root;
} col_idx;
typedef struct tbl_idx {//表名和对应的列索引
	string tableRef;
	vector<col_idx> cols;
}tbl_idx;


class IdxMgr
{
public:
	static IdxMgr* getInstance();
	static void release();
	~IdxMgr();
private:
	static IdxMgr* instance;
	IdxMgr() {}
	IdxMgr(const IdxMgr&) {}
	IdxMgr& operator=(const IdxMgr&) = delete;
public:
	bool hasIdx(Expr* tableRef,Expr* colRef);	//查询一个表的一个列上是否含有索引
	void createIdx(Expr* tableRef, Expr* colRef);	//为一个表上的一列创建索引

private:
	vector<tbl_idx> tbls;
};


#endif // !IDX_MRG_H