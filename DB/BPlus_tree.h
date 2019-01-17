#ifndef BPLUS_TREE_H
#define BPLUS_TREE_H

#include "BPlus_node.h"
#include "global.h"
#include <vector>
using namespace std;



struct SelectResult
{
	int keyIndex;
	LeafNode* targetNode;
};

class BPlusTree {
public:
	BPlusTree();
	~BPlusTree();
	bool insert(BPTKeyType key, const BPTDataType& data);
	bool remove(BPTKeyType key);
	bool update(BPTKeyType oldKey, BPTKeyType newKey);
	// ��ֵ��ѯ��compareOperator������LT(<)��LE(<=)��EQ(=)��BE(>=)��BT(>)
	vector<BPTDataType> select(BPTKeyType compareKey, int compareOpeartor);
	// ��Χ��ѯ��BETWEEN
	vector<BPTDataType> select(BPTKeyType smallKey, BPTKeyType largeKey);
	bool search(BPTKeyType key); // �����Ƿ����
	vector<BPTDataType> getAllValues();	//��������ֵ
	vector<pair<BPTKeyType,BPTDataType> > getAllKVPairs();	//�������м�ֵ��
	void clear();             // ���
	void print()const;        // ��ӡ���ؼ���
	void printData()const;    // ��ӡ����
private:
	void r_insert(Node* parentNode, BPTKeyType key, const BPTDataType& data);	//����ǰ׺r_��ʾ�ݹ麯��
	void r_remove(Node* parentNode, BPTKeyType key);
	void printInConcavo(Node *pNode, int count)const;
	bool r_search(Node *pNode, BPTKeyType key)const;
	void changeKey(Node *pNode, BPTKeyType oldKey, BPTKeyType newKey);
	void search(BPTKeyType key, SelectResult& result);
	void r_search(Node* pNode, BPTKeyType key, SelectResult& result);
	void remove(BPTKeyType key, BPTDataType& dataValue);
	void r_remove(Node* parentNode, BPTKeyType key, BPTDataType& dataValue);
private:
	Node* pRoot;
	LeafNode* pDataHead;
	BPTKeyType MaxKey;  // B+���е�����
};

#endif
