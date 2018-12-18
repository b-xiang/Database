#ifndef BUFFER_MGR_H
#define BUFFER_MGR_H
#include <vector>
#include "sql/Expr.h"
#include "Convertor.h"
#include "global.h"
#define bufferblockNum 5//缓存区一共5块
using namespace std;
using namespace hsql;

class Block;

struct BufferBlock
{
	BufferBlock* next = NULL;
	Block* blk = NULL;
};//为了实现LRU新生成的结构体包含了真正的Block

class BufferMgr {
public:
	static BufferMgr* getInstance();
	static void release();
	~BufferMgr();
private:
	BufferMgr() { head = NULL; }
	BufferMgr(const BufferMgr&) {}
	BufferMgr& operator=(const BufferMgr&) = delete;
	static BufferMgr* instance;
public:
	void initialBuffer();//初始化缓存区
	Block* findBlockById(string fileid, string blockid);//根据文件号和块号在内存中查找到这个块
	void deleteBufferBlock(string fileid, string blockid);//删除缓存区中的块
	void print();//打印缓存区中每个块的文件号和块号
private:
	BufferBlock* head;//缓冲区的头部
	
};
#endif // !BUFFER_MGR_H#pragma once
