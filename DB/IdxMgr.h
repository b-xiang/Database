#ifndef IDX_MRG_H
#define IDX_MRG_H
#include <string>
#include <vector>
#include <map>
#include "sql/Expr.h"
using namespace std;
using namespace hsql;

class BPlusTree;

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
	bool hasIdx(int attrOid);		//��ѯһ�����һ�������Ƿ�������,columnRef����Expr* Expr::makeColumnRef(char* table, char* name)���죬����table�洢������name�洢����
	void createIdx(int attrOid);	//Ϊһ�����ϵ�һ�д�������
	
private:
	BPlusTree* getBPT(int attrOid);
private:
	map<int, BPlusTree*> idx;
};


#endif // !IDX_MRG_H