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
	Block(string _fileid, string _blockid, BlockType _type=table);
	~Block();
private:
	char buffer[BLOCK_SIZE];	//读写缓存区
	/*
	块的结构：
	[	
		oooooofffbbbbbb\0
		recordnum(16位int)
		recordpos(长度为recordnum的16位int数组)
		dataType(长度为recordnum的8位uint数组)
		bodyBegin(指向记录体开始的指针)
		pctfree(32位float)
		pctused(32位float)
		空白空间

		recordnum条记录（其中字符串的\0也算作1位，int转化为64进制存放，float等数据按其本来格式存放，float4字节，不转化为base64）
	]

	o:对应databaseObjectID
	f:对应fileid
	b:对应blockid
	*/
private:
	//只在内存中的，用于控制块的变量
	int metaEnd;		//头信息结尾
	int bodyBegin;		//存储部分开始
private:
	//要写到块里的内容
	BlockType blockType;
	int recordnum;			//数据条数
	vector<int> recordpos;	//数据开始位数
	vector<ExprType> dataType;		//每条数据对应的类型，内容是ExprType枚举类型转换为64进制后的一位变量
	char databaseObjectID[7];	//6位base64，数据对象号，表明行的身份，是在索引中的还是数据字典中的还是表中的
	char fileid[4];				//3位base64，块所在文件编号
	char blockid[7];			//6位base64，块在文件内编号
	float pctfree;				//当pctfree大于PCTFREE_THRESHOLD才能存入
	float pctused;				//当pctused小于PCTUSED_THRESHOLD才能存入
	string nextblockid;			//该块在该文件的下一个块的blockid
public:
	string GetNextblockid() {
		return nextblockid;
	}

	int GetRecordnum() {
		return recordnum;
	}
	bool isAbleToInput(Expr* content);	//检测一个Expr是否能被放进块中
	bool put(Expr* content);			//向块中放入数据，Expr参见sql/Expr.h
	Expr* get(const char* rowid);		//按照块内行标号从块内提取数据，生成Expr
	vector<Expr*> get(int fromidx, int toidx);
	vector<Expr*> get(const char* fromrowid, const char* torowid);	//范围提取多个Expr
	vector<Expr*> getFromXToEnd(const char* fromrowid);				//获取从某个位置起到块尾的值
	vector<Expr*> getFromFrontToX(const char* torowid);				//获取从开始到某个位置的值
	string generateRowID();			//传入一个Expr，产生该行的rowid
	bool writeToFile();				//将该块写到文件，要求必须有文件号和文件内块号
	bool readFromFile();			//从文件读取该块，要求必须有文件号和文件内块号
	void updateBuffer();			//更新buffer，调用此函数可以根据成员变量更新buffer数组
	void updateVar();				//更新成员变量，调用此函数可以根据buffer数组更新成员变量
	bool isFull();					//判断pctfree和pctused是否符合要求
	const char* getFileid();
	const char* getBlockid();
private:
	int getMetaEnd();
	void setMetaEnd(int _metaEnd);
	int getBodyBegin();
	void setBodyBgein(int _bodyBegin);
	void writeToBuffer(int begin, char* text);
	string getFileName();
	Expr* get(int idx);
	
private:
	class putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e) = 0;
	};
	class putIntStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e);
	};
	class putFloatStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e);
	};
	class putStringStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e);
	};
	class putArrayStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e);
	};


	class getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx) = 0;
	};
	class getIntStrategy :public getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx);
	};
	class getFloatStrategy :public getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx);
	};
	class getStringStrategy :public getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx);
	};
	class getArrayStrategy :public getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx);
	};

private:
	static putStrategy* getPutStrategy(ExprType type) {
		putStrategy* str;
		if (type == kExprLiteralInt)
			str = new putIntStrategy;
		else if (type == kExprLiteralFloat)
			str = new putFloatStrategy;
		else if (type == kExprLiteralString)
			str = new putStringStrategy;
		else if (type == kExprArray)
			str = new putArrayStrategy;
		return str;
	}
	static getStrategy* getGetStrategy(ExprType type) {
		getStrategy* str;
		if (type == kExprLiteralInt)
			str = new getIntStrategy;
		else if (type == kExprLiteralFloat)
			str = new getFloatStrategy;
		else if (type == kExprLiteralString)
			str = new getStringStrategy;
		else if (type == kExprArray)
			str = new getArrayStrategy;
		return str;
	}
};

#endif // !BLOCK_H