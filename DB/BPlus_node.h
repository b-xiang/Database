#ifndef BPLUS_NODE_H
#define BPLUS_NODE_H
#include "global.h"
#include <string>
using namespace std;

enum NODE_TYPE { INTERNAL, LEAF };        // 结点类型：内结点、叶子结点
enum SIBLING_DIRECTION { LEFT, RIGHT };   // 兄弟结点方向：左兄弟结点、右兄弟结点

// 结点基类
class Node {
public:
	Node();
	virtual ~Node();

	NODE_TYPE getType() const { return m_Type; }
	void setType(NODE_TYPE type) { m_Type = type; }
	int getKeyNum() const { return m_KeyNum; }
	void setKeyNum(int n) { m_KeyNum = n; }
	BPTKeyType getKeyValue(int i) const { return m_KeyValues[i]; }
	void setKeyValue(int i, BPTKeyType key) { m_KeyValues[i] = key; }
	int getKeyIndex(BPTKeyType key)const;  // 找到键值在结点中存储的下标
										// 纯虚函数，定义接口
	virtual void removeKey(int keyIndex, int childIndex) = 0;  // 从结点中移除键值
	virtual void split(Node* parentNode, int childIndex) = 0; // 分裂结点
	virtual void mergeChild(Node* parentNode, Node* childNode, int keyIndex) = 0;  // 合并结点
	virtual void clear() = 0; // 清空结点，同时会清空结点所包含的子树结点
	virtual void borrowFrom(Node* destNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d) = 0; // 从兄弟结点中借一个键值
	virtual int getChildIndex(BPTKeyType key, int keyIndex)const = 0;  // 根据键值获取孩子结点指针下标
protected:
	NODE_TYPE m_Type;
	int m_KeyNum;
	BPTKeyType m_KeyValues[MAXNUM_KEY];
};

// 内结点
class InternalNode : public Node {
public:
	InternalNode();
	virtual ~InternalNode();

	Node* getChild(int i) const { return m_Childs[i]; }
	void setChild(int i, Node* child) { m_Childs[i] = child; }
	void insert(int keyIndex, int childIndex, BPTKeyType key, Node* childNode);
	virtual void split(Node* parentNode, int childIndex);
	virtual void mergeChild(Node* parentNode, Node* childNode, int keyIndex);
	virtual void removeKey(int keyIndex, int childIndex);
	virtual void clear();
	virtual void borrowFrom(Node* destNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d);
	virtual int getChildIndex(BPTKeyType key, int keyIndex)const;
private:
	Node* m_Childs[MAXNUM_CHILD];
};

// 叶子结点
class LeafNode : public Node {
public:
	LeafNode();
	virtual ~LeafNode();

	LeafNode* getLeftSibling() const { return m_LeftSibling; }
	void setLeftSibling(LeafNode* node) { m_LeftSibling = node; }
	LeafNode* getRightSibling() const { return m_RightSibling; }
	void setRightSibling(LeafNode* node) { m_RightSibling = node; }
	BPTDataType getData(int i) const { return m_Datas[i]; }
	void setData(int i, const BPTDataType& data) { m_Datas[i] = data; }
	void insert(BPTKeyType key, const BPTDataType& data);
	virtual void split(Node* parentNode, int childIndex);
	virtual void mergeChild(Node* parentNode, Node* childNode, int keyIndex);
	virtual void removeKey(int keyIndex, int childIndex);
	virtual void clear();
	virtual void borrowFrom(Node* destNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d);
	virtual int getChildIndex(BPTKeyType key, int keyIndex)const;
private:
	LeafNode* m_LeftSibling;
	LeafNode* m_RightSibling;
	BPTDataType m_Datas[MAXNUM_LEAF];
};
#endif