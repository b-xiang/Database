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
	char buffer[BLOCK_SIZE];	//��д������
	/*
	��Ľṹ��
	[	
		oooooofffbbbbbb\0
		recordnum(base64��int)
		nextblockid(base64��int)
		recordpos(����Ϊrecordnum��16λint����)
		dataType(����Ϊrecordnum��8λuint����)
		bodyBegin(ָ���¼�忪ʼ��ָ��)
		pctfree(32λfloat)
		pctused(32λfloat)
		�հ׿ռ�

		recordnum����¼�������ַ�����\0Ҳ����1λ��intת��Ϊ64���ƴ�ţ�float�����ݰ��䱾����ʽ��ţ�float4�ֽڣ���ת��Ϊbase64��
	]

	o:��ӦdatabaseObjectID
	f:��Ӧfileid
	b:��Ӧblockid
	*/
private:
	//ֻ���ڴ��еģ����ڿ��ƿ�ı���
	int metaEnd;		//ͷ��Ϣ��β
	int bodyBegin;		//�洢���ֿ�ʼ
private:
	//Ҫд�����������
	BlockType blockType;
	int recordnum;			//��������
	vector<int> recordpos;	//���ݿ�ʼλ��
	vector<ExprType> dataType;		//ÿ�����ݶ�Ӧ�����ͣ�������ExprTypeö������ת��Ϊ64���ƺ��һλ����
	char databaseObjectID[7];	//6λbase64�����ݶ���ţ������е���ݣ����������еĻ��������ֵ��еĻ��Ǳ��е�
	char fileid[4];				//3λbase64���������ļ����
	char blockid[7];			//6λbase64�������ļ��ڱ��
	float pctfree;				//��pctfree����PCTFREE_THRESHOLD���ܴ���
	float pctused;				//��pctusedС��PCTUSED_THRESHOLD���ܴ���
	int nextblockid;			//�ÿ��ڸ��ļ�����һ�����blockid
public:
	void setNextBlockid(string id);
	string GetNextblockid();
	int GetRecordnum() {
		return recordnum;
	}
	bool isAbleToInput(Expr* content);		//���һ��Expr�Ƿ��ܱ��Ž�����
	bool isAbleToUpdate(Expr* content);	//���һ�������µ�Expr�Ƿ��ܱ��Ž�����
	string put(Expr* content,int beginPos=-1);			//����з������ݣ�Expr�μ�sql/Expr.h
	void remove(const char* rowid);	//ɾ������Ԫ��
	void update(const char* rowid, Expr* newContent);//����Ԫ��
	Expr* get(const char* rowid);		//���տ����б�Ŵӿ�����ȡ���ݣ�����Expr
	vector<Expr*> get(int fromidx, int toidx);
	vector<Expr*> get(const char* fromrowid, const char* torowid);	//��Χ��ȡ���Expr
	vector<Expr*> getFromXToEnd(const char* fromrowid);				//��ȡ��ĳ��λ���𵽿�β��ֵ
	vector<Expr*> getFromFrontToX(const char* torowid);				//��ȡ�ӿ�ʼ��ĳ��λ�õ�ֵ
	string generateRowID();			//����һ��Expr���������е�rowid
	bool writeToFile();				//���ÿ�д���ļ���Ҫ��������ļ��ź��ļ��ڿ��
	bool readFromFile();			//���ļ���ȡ�ÿ飬Ҫ��������ļ��ź��ļ��ڿ��
	void updateBuffer();			//����buffer�����ô˺������Ը��ݳ�Ա��������buffer����
	void updateVar();				//���³�Ա���������ô˺������Ը���buffer������³�Ա����
	bool isFull();					//�ж�pctfree��pctused�Ƿ����Ҫ��
	void setBlockType(BlockType blkType);			//����blockType
	BlockType getBlockType();		//��ȡblockType
	const char* getFileid();
	const char* getBlockid();
	static string encodeExprArray(Expr* e);
	static Expr* decodeExprArray(string str);
private:
	int getMetaEnd();
	void setMetaEnd(int _metaEnd);
	int getBodyBegin();
	void setBodyBgein(int _bodyBegin);
	void writeToBuffer(int begin, char* text);
	string getFileName();
	Expr* get(int idx);
	void remove(int idx);
	int getEncodeLength(Expr*e);
private:
	class putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e, int from) = 0;
	};
	class putIntStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e, int from);
	};
	class putFloatStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e, int from);
	};
	class putStringStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e, int from);
	};
	class putArrayStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e, int from);
	};
	class putNullStrategy :public putStrategy {
	public:
		virtual bool put(Block *blk, Expr* e, int from);
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
	class getDeletedStrategy :public getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx);
	};
	class getUpdatedStrategy :public getStrategy {
	public:
		virtual Expr* get(Block*blk, int idx);
	};
	class getNullStrategy :public getStrategy {
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
		else if (type == kExprLiteralNull)
			str = new putNullStrategy;
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
		else if (type == kExprDeleted)
			str = new  getDeletedStrategy;
		else if (type == kExprUpdated)
			str = new getUpdatedStrategy;
		else if (type == kExprLiteralNull)
			str = new getNullStrategy;
		return str;
	}
};

#endif // !BLOCK_H