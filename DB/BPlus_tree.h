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
	// 定值查询，compareOperator可以是LT(<)、LE(<=)、EQ(=)、BE(>=)、BT(>)
	vector<BPTDataType> select(BPTKeyType compareKey, int compareOpeartor);
	// 范围查询，BETWEEN
	vector<BPTDataType> select(BPTKeyType smallKey, BPTKeyType largeKey);
	bool search(BPTKeyType key); // 查找是否存在
	vector<BPTDataType> getAllValues();	//返回所有值
	vector<pair<BPTKeyType,BPTDataType> > getAllKVPairs();	//返回所有键值对
	void clear();             // 清空
	void print()const;        // 打印树关键字
	void printData()const;    // 打印数据
private:
	void r_insert(Node* parentNode, BPTKeyType key, const BPTDataType& data);	//带有前缀r_表示递归函数
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
	BPTKeyType MaxKey;  // B+树中的最大键
};

#endif
