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
	Block(BlockType _type,string _fileid, string _blockid);
	Block(string _fileid, string _blockid);
	~Block();
private:
	char buffer[BLOCK_SIZE];	//��д������
	/*
	��Ľṹ��
	[	
		oooooofffbbbbbb\0
		pctfree(32λfloat)
		pctused(32λfloat)
		recordnum(16λint)
		recordpos(����Ϊrecordnum��16λint����)
		dataType(����Ϊrecordnum��8λuint����)

		�հ׿ռ�

		recordnum����¼�������ַ�����\0Ҳ����1λ��int��float�����ݰ��䱾����ʽ��ţ�int4�ֽڣ�float4�ֽڣ���ת��Ϊbase64��
	]

	o:��ӦdatabaseObjectID
	f:��Ӧfileid
	b:��Ӧblockid
	*/
private:
	//ֻ���ڴ��еģ����ڿ��ƿ�ı���
	int16 metaEnd;		//ͷ��Ϣ��β
	int16 bodyBegin;	//�洢���ֿ�ʼ
private:
	//Ҫд�����������
	BlockType blockType;
	int16 recordnum;			//��������
	vector<int16> recordpos;	//���ݿ�ʼλ��
	vector<uint8> dataType;		//ÿ�����ݶ�Ӧ������
	char databaseObjectID[7];	//6λbase64�����ݶ���ţ������е���ݣ����������еĻ��������ֵ��еĻ��Ǳ��е�
	char fileid[4];				//3λbase64���������ļ����
	char blockid[7];			//6λbase64�������ļ��ڱ��
	float pctfree;		//��pctfree����PCTFREE_THRESHOLD���ܴ���
	float pctused;		//��pctusedС��PCTUSED_THRESHOLD���ܴ���
public:
	bool isAbleToInput(Expr content);	//���һ��Expr�Ƿ��ܱ��Ž�����
	bool put(Expr content);			//����з������ݣ�Expr�μ�sql/Expr.h
	Expr get(char* rowid);			//���տ����б�Ŵӿ�����ȡ���ݣ�����Expr
	string generateRowID(Expr content);//����һ��Expr���������е�rowid
	bool writeToFile();				//���ÿ�д���ļ���Ҫ��������ļ��ź��ļ��ڿ��
	bool readFromFile();			//���ļ���ȡ�ÿ飬Ҫ��������ļ��ź��ļ��ڿ��
private:
	void writeToBuffer(int begin, char* text);
	int getMetaEnd();
	void setMetaEnd(int _metaEnd);
	int getBodyBegin();
	void setBodyBgein(int _bodyBegin);
	void updateBuffer();			//����buffer�����ô˺������Ը��ݳ�Ա��������buffer����
	void updateVar();				//���³�Ա���������ô˺������Ը���buffer������³�Ա����
	string getFileName();
	Expr get(int16 idx);
};


#endif // !BLOCK_H