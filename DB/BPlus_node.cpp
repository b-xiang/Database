#include "BPlus_node.h"

// Node
Node::Node() {
	setType(LEAF);
	setKeyNum(0);
}

Node::~Node() {
	setKeyNum(0);
}

int Node::getKeyIndex(BPTKeyType key)const
{
	int left = 0;
	int right = getKeyNum() - 1;
	int current;
	while (left != right)
	{
		current = (left + right) / 2;
		BPTKeyType currentKey = getKeyValue(current);
		if (key>currentKey)
		{
			left = current + 1;
		}
		else
		{
			right = current;
		}
	}
	return left;
}
/*
int Node::getKeyIndex(BPTKeyType key) const
{
	int low = 0;
	int mid = 0;
	int high = getKeyNum() - 1;

	while (low < high)
	{
		mid = (low + high) >> 1; // 中点值
		BPTKeyType midKey = getKeyValue(mid);
		if (key > midKey)
		{
			low = mid + 1;
		}
		else if (key < midKey)
		{
			high = mid - 1;
		}
		else
		{
			return mid + 1;
		}
	}
	// low=high
	if (key < getKeyValue(low))
	{
		return mid;
	}
	else
	{
		return mid + 1;
	}
}
*/

// InternalNode
InternalNode::InternalNode() :Node() {
	setType(INTERNAL);
}

InternalNode::~InternalNode() {
//???
	//delete[] m_Childs;
}

void InternalNode::clear()
{
	for (int i = 0; i <= m_KeyNum; ++i)
	{
		m_Childs[i]->clear();
		delete m_Childs[i];
		m_Childs[i] = NULL;
	}
}

void InternalNode::split(Node* parentNode, int childIndex)
{
	InternalNode* newNode = new InternalNode();//分裂后的右节点
	newNode->setKeyNum(MINNUM_KEY);
	int i;
	for (i = 0; i<MINNUM_KEY; ++i)// 拷贝关键字的值
	{
		newNode->setKeyValue(i, m_KeyValues[i + MINNUM_CHILD]);
	}
	for (i = 0; i<MINNUM_CHILD; ++i) // 拷贝孩子节点指针
	{
		newNode->setChild(i, m_Childs[i + MINNUM_CHILD]);
	}
	setKeyNum(MINNUM_KEY);  //更新左子树的关键字个数
	((InternalNode*)parentNode)->insert(childIndex, childIndex + 1, m_KeyValues[MINNUM_KEY], newNode);
}

void InternalNode::insert(int keyIndex, int childIndex, BPTKeyType key, Node* childNode) {
	int i;
	for (i = getKeyNum(); i>keyIndex; --i)//将父节点中的childIndex后的所有关键字的值和子树指针向后移一位
	{
		setChild(i + 1, m_Childs[i]);
		setKeyValue(i, m_KeyValues[i - 1]);
	}
	if (i == childIndex)
	{
		setChild(i + 1, m_Childs[i]);
	}
	setChild(childIndex, childNode);
	setKeyValue(keyIndex, key);
	setKeyNum(m_KeyNum + 1);
}

void InternalNode::mergeChild(Node* parentNode, Node* childNode, int keyIndex)
{
	// 合并数据
	insert(MINNUM_KEY, MINNUM_KEY + 1, parentNode->getKeyValue(keyIndex), ((InternalNode*)childNode)->getChild(0));
	int i;
	for (i = 1; i <= childNode->getKeyNum(); ++i)
	{
		insert(MINNUM_KEY + i, MINNUM_KEY + i + 1, childNode->getKeyValue(i - 1), ((InternalNode*)childNode)->getChild(i));
	}
	//父节点删除index的key
	parentNode->removeKey(keyIndex, keyIndex + 1);
	delete ((InternalNode*)parentNode)->getChild(keyIndex + 1);
}

void InternalNode::removeKey(int keyIndex, int childIndex)
{
	for (int i = 0; i<getKeyNum() - keyIndex - 1; ++i)
	{
		setKeyValue(keyIndex + i, getKeyValue(keyIndex + i + 1));
		setChild(childIndex + i, getChild(childIndex + i + 1));
	}
	setKeyNum(getKeyNum() - 1);
}

void InternalNode::borrowFrom(Node* siblingNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d)
{
	switch (d)
	{
	case LEFT:  // 从左兄弟结点借
	{
		insert(0, 0, parentNode->getKeyValue(keyIndex), ((InternalNode*)siblingNode)->getChild(siblingNode->getKeyNum()));
		parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(siblingNode->getKeyNum() - 1));
		siblingNode->removeKey(siblingNode->getKeyNum() - 1, siblingNode->getKeyNum());
	}
	break;
	case RIGHT:  // 从右兄弟结点借
	{
		insert(getKeyNum(), getKeyNum() + 1, parentNode->getKeyValue(keyIndex), ((InternalNode*)siblingNode)->getChild(0));
		parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(0));
		siblingNode->removeKey(0, 0);
	}
	break;
	default:
		break;
	}
}

int InternalNode::getChildIndex(BPTKeyType key, int keyIndex)const
{
	if (key == getKeyValue(keyIndex))
	{
		return keyIndex + 1;
	}
	else
	{
		return keyIndex;
	}
}

// LeafNode
LeafNode::LeafNode() :Node() {
	setType(LEAF);
	setLeftSibling(NULL);
	setRightSibling(NULL);
}

LeafNode::~LeafNode() {

}

void LeafNode::clear()
{
	for (int i = 0; i<m_KeyNum; ++i)
	{
		// if type of m_Datas is pointer
		//delete m_Datas[i];
		//m_Datas[i] = NULL;
	}
}

void LeafNode::insert(BPTKeyType key, const BPTDataType& data)
{
	int i;
	for (i = m_KeyNum; i >= 1 && m_KeyValues[i - 1]>key; --i)
	{
		setKeyValue(i, m_KeyValues[i - 1]);
		setData(i, m_Datas[i - 1]);
	}
	setKeyValue(i, key);
	setData(i, data);
	setKeyNum(m_KeyNum + 1);
}

void LeafNode::split(Node* parentNode, int childIndex)
{
	LeafNode* newNode = new LeafNode();//分裂后的右节点
	setKeyNum(MINNUM_LEAF);
	newNode->setKeyNum(MINNUM_LEAF + 1);
	newNode->setRightSibling(getRightSibling());
	setRightSibling(newNode);
	newNode->setLeftSibling(this);
	int i;
	for (i = 0; i<MINNUM_LEAF + 1; ++i)// 拷贝关键字的值
	{
		newNode->setKeyValue(i, m_KeyValues[i + MINNUM_LEAF]);
	}
	for (i = 0; i<MINNUM_LEAF + 1; ++i)// 拷贝数据
	{
		newNode->setData(i, m_Datas[i + MINNUM_LEAF]);
	}
	((InternalNode*)parentNode)->insert(childIndex, childIndex + 1, m_KeyValues[MINNUM_LEAF], newNode);
}

void LeafNode::mergeChild(Node* parentNode, Node* childNode, int keyIndex)
{
	// 合并数据
	for (int i = 0; i<childNode->getKeyNum(); ++i)
	{
		insert(childNode->getKeyValue(i), ((LeafNode*)childNode)->getData(i));
	}
	setRightSibling(((LeafNode*)childNode)->getRightSibling());
	//父节点删除index的key，
	parentNode->removeKey(keyIndex, keyIndex + 1);
}

void LeafNode::removeKey(int keyIndex, int childIndex)
{
	for (int i = keyIndex; i<getKeyNum() - 1; ++i)
	{
		setKeyValue(i, getKeyValue(i + 1));
		setData(i, getData(i + 1));
	}
	setKeyNum(getKeyNum() - 1);
}

void LeafNode::borrowFrom(Node* siblingNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d)
{
	switch (d)
	{
	case LEFT:  // 从左兄弟结点借
	{
		insert(siblingNode->getKeyValue(siblingNode->getKeyNum() - 1), ((LeafNode*)siblingNode)->getData(siblingNode->getKeyNum() - 1));
		siblingNode->removeKey(siblingNode->getKeyNum() - 1, siblingNode->getKeyNum() - 1);
		parentNode->setKeyValue(keyIndex, getKeyValue(0));
	}
	break;
	case RIGHT:  // 从右兄弟结点借
	{
		insert(siblingNode->getKeyValue(0), ((LeafNode*)siblingNode)->getData(0));
		siblingNode->removeKey(0, 0);
		parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(0));
	}
	break;
	default:
		break;
	}
}

int LeafNode::getChildIndex(BPTKeyType key, int keyIndex)const
{
	return keyIndex;
}