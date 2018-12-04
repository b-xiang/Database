#ifndef IDX_MRG_H
#define IDX_MRG_H
#include <string>
#include <map>
using namespace std;

class BPlusTree;

typedef struct idx_pair {
	string tablename;
	string col;
	BPlusTree* root;
} idx_pair;

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
private:
};


#endif // !IDX_MRG_H