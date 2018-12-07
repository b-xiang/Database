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
	col_idx(string _colRef, BPlusTree* _root) {
		colRef = _colRef;
		root = _root;
	}
} col_idx;
typedef struct tbl_idx {//�����Ͷ�Ӧ��������
	string tableRef;
	vector<col_idx*> cols;
	tbl_idx(string _tableRef) {
		tableRef = _tableRef;
	}
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
	bool hasIdx(Expr* columnRef);		//��ѯһ�����һ�������Ƿ�������,columnRef����Expr* Expr::makeColumnRef(char* table, char* name)���죬����table�洢������name�洢����
	void createIdx(Expr* columnRef);	//Ϊһ�����ϵ�һ�д�������
	
private:
	BPlusTree* getBPT(Expr* columnRef);
private:
	vector<tbl_idx*> tbls;
};


#endif // !IDX_MRG_H