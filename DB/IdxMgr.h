#ifndef IDX_MRG_H
#define IDX_MRG_H
#include <string>
#include <vector>
#include "sql/Expr.h"
using namespace std;
using namespace hsql;

class BPlusTree;


typedef struct col_idx {//�����Ͷ�Ӧ��B+���ĸ�
	string colRef;
	BPlusTree* root;
} col_idx;
typedef struct tbl_idx {//�����Ͷ�Ӧ��������
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
	bool hasIdx(Expr* tableRef,Expr* colRef);	//��ѯһ�����һ�������Ƿ�������
	void createIdx(Expr* tableRef, Expr* colRef);	//Ϊһ�����ϵ�һ�д�������

private:
	vector<tbl_idx> tbls;
};


#endif // !IDX_MRG_H