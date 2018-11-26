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
	int16 blockNum;
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
	bool isFileFull(const char* fileid);									//文件是否已经放满
	bool isAbleToInput(const char* fileid,const char* blockid, Expr content);	//一个块内是否还能放入Expr
	bool isAbleToInput(Block* block, Expr content);					
	const char* allocBlock(const char* fileid,BlockType bt=table);				//向一个文件内分配块,返回文件号加块号
	const char* allocFile();												//新创建一个文件,返回文件号
	Block* getBlock(const char* fileid, const char* blockid);					//根据fileid和blockid查找块,注意内存泄露！在函数内new了新的block，使用后需要自己delete
	file* getFile(const char* fileid);									//根据fileid查找file
private:
	vector<file> files;
	Block* b;		//用于防止getBlock函数的内存泄漏
};

#endif // !BLOCK_MGR_H