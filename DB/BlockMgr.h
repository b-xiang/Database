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
	int fileid;			//int型文件号
	char fileid64[4];	//3位64进制文件号
	int blockNum;		//文件内块数目
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
	bool isFileFull(string fileid);										//文件是否已经放满
	bool isAbleToInput(string fileid,string blockid, Expr* content);	//一个块内是否还能放入Expr
	bool isAbleToInput(Block* block, Expr* content);					
	string allocBlock(string fileid,BlockType bt=table);			//向一个文件内分配块,返回文件号加块号
	string allocFile();											//新创建一个文件,返回文件号
	Block* getBlock(string fileid, string blockid);					//根据fileid和blockid查找块,注意内存泄露！在函数内new了新的block，使用后需要自己delete
	file getFile(string fileid);									//根据fileid查找file
	vector<string> multiplePut(vector<Expr*> records);			//自动将多条数据存入块中，返回各条记录的rowid
	vector<Expr*> multipleGet(vector<string> rowids);			//根据多条rowid自动获取多条记录
	Block* getLastAvailableBlock(string fileid);					//获取一个文件中最后一个可用的块
	file* getLastAvailableFile();									//获取第一个可用的文件，如果所有文件都满了，可以自动调用allocFile新建文件
private:
	void releaseBlk(Block* blk);						//释放block
private:
	vector<file> files;
};

#endif // !BLOCK_MGR_H