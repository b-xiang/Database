#ifndef BPLUS_TREE_H
#define BPLUS_TREE_H

#include "BPlus_node.h"
#include <vector>
using namespace std;

enum COMPARE_OPERATOR { LT, LE, EQ, BE, BT, BETWEEN }; // 比较操作符：<、<=、=、>=、>、<>
const int INVALID_INDEX = -1;

struct SelectResult
{
	int keyIndex;
	LeafNode* targetNode;
};

class BPlusTree {
public:
	BPlusTree();
	~BPlusTree();
	bool insert(KeyType key, const DataType& data);
	bool remove(KeyType key);
	bool update(KeyType oldKey, KeyType newKey);
	// 定值查询，compareOperator可以是LT(<)、LE(<=)、EQ(=)、BE(>=)、BT(>)
	vector<DataType> select(KeyType compareKey, int compareOpeartor);
	// 范围查询，BETWEEN
	vector<DataType> select(KeyType smallKey, KeyType largeKey);
	bool search(KeyType key); // 查找是否存在
	vector<DataType> getAllValues();	//返回所有值
	vector<pair<KeyType,DataType> > getAllKVPairs();	//返回所有键值对
	void clear();             // 清空
	void print()const;        // 打印树关键字
	void printData()const;    // 打印数据
private:
	void r_insert(Node* parentNode, KeyType key, const DataType& data);	//带有前缀r_表示递归函数
	void r_remove(Node* parentNode, KeyType key);
	void printInConcavo(Node *pNode, int count)const;
	bool r_search(Node *pNode, KeyType key)const;
	void changeKey(Node *pNode, KeyType oldKey, KeyType newKey);
	void search(KeyType key, SelectResult& result);
	void r_search(Node* pNode, KeyType key, SelectResult& result);
	void remove(KeyType key, DataType& dataValue);
	void r_remove(Node* parentNode, KeyType key, DataType& dataValue);
private:
	Node* pRoot;
	LeafNode* pDataHead;
	KeyType MaxKey;  // B+树中的最大键
};

#endif
