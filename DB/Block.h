#ifndef BLOCK_H
#define BLOCK_H
#include "global.h"
#include "sql/Expr.h"
#include <string>
using namespace hsql;
using namespace std;

class Block
{
public:
	Block(BlockType _type,const char* _fileid, const char* _blockid);
	Block(const char* _fileid, const char* _blockid);
	~Block();
private:
	char buffer[BLOCK_SIZE];	//读写缓存区
	/*
	块的结构：
	[	
		oooooofffbbbbbb\0
		pctfree(32位float)
		pctused(32位float)
		recordnum(16位int)
		recordpos(长度为recordnum的16位int数组)
		dataType(长度为recordnum的8位uint数组)

		空白空间

		recordnum条记录（其中字符串的\0也算作1位，int或float等数据按其本来格式存放，int4字节，float4字节，不转化为base64）
	]

	o:对应databaseObjectID
	f:对应fileid
	b:对应blockid
	*/
private:
	//只在内存中的，用于控制块的变量
	int16 metaEnd;		//头信息结尾
	int16 bodyBegin;	//存储部分开始
	int16 arrayLen;		//recordpos和dataType数组的长度
private:
	//要写到块里的内容
	BlockType blockType;
	int16 recordnum;			//数据条数
	vector<int16> recordpos;	//数据开始位数
	vector<uint8> dataType;		//每条数据对应的类型
	char databaseObjectID[7];	//6位base64，数据对象号，表明行的身份，是在索引中的还是数据字典中的还是表中的
	char fileid[4];				//3位base64，块所在文件编号
	char blockid[7];			//6位base64，块在文件内编号
	float pctfree;		//当pctfree大于PCTFREE_THRESHOLD才能存入
	float pctused;		//当pctused小于PCTUSED_THRESHOLD才能存入
public:
	bool isAbleToInput(Expr content);	//检测一个Expr是否能被放进块中
	bool put(Expr content);			//向块中放入数据，Expr参见sql/Expr.h
	Expr get(char* rowid);			//按照块内行标号从块内提取数据，生成Expr
	const char* generateRowID(Expr content);//传入一个Expr，产生该行的rowid
	bool writeToFile();				//将该块写到文件，要求必须有文件号和文件内块号
	bool readFromFile();			//从文件读取该块，要求必须有文件号和文件内块号
private:
	void writeToBuffer(int begin, char* text);
	int getMetaEnd();
	void setMetaEnd(int _metaEnd);
	int getBodyBegin();
	void setBodyBgein(int _bodyBegin);
	void updateBuffer();			//更新buffer，调用此函数可以根据成员变量更新buffer数组
	void updateVar();				//更新成员变量，调用此函数可以根据buffer数组更新成员变量
	string getFileName();
	Expr get(int16 idx);
};


#endif // !BLOCK_H