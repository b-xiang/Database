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
	int fileid;			//int���ļ���
	char fileid64[4];	//3λ64�����ļ���
	int blockNum;		//�ļ��ڿ���Ŀ
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
	bool isFileFull(string fileid);										//�ļ��Ƿ��Ѿ�����
	bool isAbleToInput(string fileid,string blockid, Expr* content);	//һ�������Ƿ��ܷ���Expr
	bool isAbleToInput(Block* block, Expr* content);					
	string allocBlock(string fileid,BlockType bt=table);			//��һ���ļ��ڷ����,�����ļ��żӿ��
	string allocFile();											//�´���һ���ļ�,�����ļ���
	Block* getBlock(string fileid, string blockid);					//����fileid��blockid���ҿ�,ע���ڴ�й¶���ں�����new���µ�block��ʹ�ú���Ҫ�Լ�delete
	file getFile(string fileid);									//����fileid����file
	vector<string> multiplePut(vector<Expr*> records);			//�Զ����������ݴ�����У����ظ�����¼��rowid
	vector<Expr*> multipleGet(vector<string> rowids);			//���ݶ���rowid�Զ���ȡ������¼
	Block* getLastAvailableBlock(string fileid);					//��ȡһ���ļ������һ�����õĿ�
	file* getLastAvailableFile();									//��ȡ��һ�����õ��ļ�����������ļ������ˣ������Զ�����allocFile�½��ļ�
private:
	void releaseBlk(Block* blk);						//�ͷ�block
private:
	vector<file> files;
};

#endif // !BLOCK_MGR_H