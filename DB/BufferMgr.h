#ifndef BUFFER_MGR_H
#define BUFFER_MGR_H
#include <vector>
#include "sql/Expr.h"
#include "Convertor.h"
#include "global.h"
using namespace std;
using namespace hsql;

class Block;

struct BufferBlock
{
	BufferBlock* next = NULL;
	Block* blk = NULL;
};//Ϊ��ʵ��LRU�����ɵĽṹ�������������Block

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
	void initialBuffer();//��ʼ��������
	Block* findBlockById(string fileid, string blockid);//�����ļ��źͿ�����ڴ��в��ҵ������
	void deleteBufferBlock(string fileid, string blockid);//ɾ���������еĿ�
	void print();//��ӡ��������ÿ������ļ��źͿ��
private:
	BufferBlock* head;//��������ͷ��
	
};
#endif // !BUFFER_MGR_H#pragma once
