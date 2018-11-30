#ifndef BLOCK_MGR_H
#define BLOCK_MGR_H
#include <vector>
#include "sql/Expr.h"
#include "Convertor.h"
#include "global.h"
using namespace std;
using namespace hsql;

class Block;

typedef struct file {
	int fileid;
	char fileid64[4];
	int blockNum;
	file() {}
	file(int _fileid, int _blocknum = 0) {
		fileid = _fileid;
		blockNum = _blocknum;
		strcpy(fileid64,Conv64::to_64(fileid,3).c_str());
	}
}file;

class BlockMgr
{
public:
	static BlockMgr* getInstance();
	static void release();
	~BlockMgr();
private:
	static BlockMgr* instance;
	BlockMgr() {}
	BlockMgr(const BlockMgr&) {}
	BlockMgr& operator=(const BlockMgr&)=delete;
public:
	bool isFileFull(string fileid);									//文件是否已经放满
	bool isAbleToInput(string fileid,string blockid, Expr* content);	//一个块内是否还能放入Expr
	bool isAbleToInput(Block* block, Expr* content);					
	string allocBlock(string fileid,BlockType bt=table);				//向一个文件内分配块,返回文件号加块号
	string allocFile();												//新创建一个文件,返回文件号
	Block* getBlock(string fileid, string blockid);					//根据fileid和blockid查找块,注意内存泄露！在函数内new了新的block，使用后需要自己delete
	file* getFile(string fileid);									//根据fileid查找file
private:
	vector<file> files;
};

#endif // !BLOCK_MGR_H