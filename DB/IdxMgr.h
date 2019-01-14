#ifndef IDX_MRG_H
#define IDX_MRG_H
#include <string>
#include <vector>
#include <map>
#include "sql/Expr.h"
#include "global.h"
using namespace std;


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
	bool hasIdx(int attrOid);		//查询一个表的一个列上是否含有索引,columnRef利用Expr* Expr::makeColumnRef(char* table, char* name)构造，其中table存储表名，name存储列名
	void createIdx(int attrOid);	//为一个表上的一列创建索引
	void addRecord(int attrOid, hsql::Expr* expr, string rid);	//为索引添加一条记录
	vector<BPTDataType> getRowids(int attrOid, vector< hsql::Expr*> expr);
	vector<BPTDataType> getRowids(int attrOid);
private:
	BPlusTree* getBPT(int attrOid);
	BPTKeyType generateKey(hsql::Expr* expr);
private:
	map<int, BPlusTree*> idx;
};


#endif // !IDX_MRG_H