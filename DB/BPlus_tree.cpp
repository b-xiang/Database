#include "BPlus_tree.h"
#include <iostream>
#include <algorithm>
using namespace std;

BPlusTree::BPlusTree() {
	pRoot = NULL;
	pDataHead = NULL;
}

BPlusTree::~BPlusTree() {
	clear();
}

bool BPlusTree::insert(KeyType key, const DataType& data) {
	// 是否已经存在
	if (search(key))
	{
		return false;
	}
	// 找到可以插入的叶子结点,否则创建新的叶子结点
	if (pRoot == NULL)
	{
		pRoot = new LeafNode();
		pDataHead = (LeafNode*)pRoot;
		MaxKey = key;
	}
	if (pRoot -> getKeyNum()>= MAXNUM_KEY) // 根结点已满,分裂
	{
		InternalNode* newNode = new InternalNode();  //创建新的根节点
		newNode -> setChild(0, pRoot);
		pRoot -> split(newNode, 0);    // 叶子结点分裂
		pRoot = newNode;  //更新根节点指针
	}
	if (key> MaxKey)  // 更新最大键值
	{
		MaxKey = key;
	}
	r_insert(pRoot, key, data);
	return true;
}

void BPlusTree::r_insert(Node* parentNode, KeyType key, const DataType& data)
{
	if (parentNode -> getType() == LEAF)  // 叶子结点,直接插入
	{
		((LeafNode*)parentNode) -> insert(key, data);
	}
	else
	{
		// 找到子结点
		int keyIndex = parentNode -> getKeyIndex(key);
		int childIndex = parentNode -> getChildIndex(key, keyIndex); // 孩子结点指针索引
		Node* childNode = ((InternalNode*)parentNode) -> getChild(childIndex);
		if (childNode -> getKeyNum()>= MAXNUM_LEAF)  // 子结点已满,需进行分裂
		{
			childNode -> split(parentNode, childIndex);
			if (parentNode -> getKeyValue(childIndex) <= key)   // 确定目标子结点
			{
				childNode = ((InternalNode*)parentNode) -> getChild(childIndex + 1);
			}
		}
		r_insert(childNode, key, data);
	}
}

void BPlusTree::clear()
{
	if (pRoot != NULL)
	{
		pRoot -> clear();
		delete pRoot;
		pRoot = NULL;
		pDataHead = NULL;
	}
}

bool BPlusTree::search(KeyType key)
{
	return r_search(pRoot, key);
}

vector<DataType> BPlusTree::getAllValues()
{
	vector<DataType> res;
	LeafNode* itr = pDataHead;
	while (itr != NULL)
	{
		for (int i = 0; i< itr->getKeyNum(); ++i)
		{
			res.push_back(itr->getData(i));
		}
		itr = itr->getRightSibling();
	}
	return res;
}

vector<pair<KeyType, DataType>> BPlusTree::getAllKVPairs()
{
	vector<pair<KeyType,DataType> > res;
	LeafNode* itr = pDataHead;
	while (itr != NULL)
	{
		for (int i = 0; i< itr->getKeyNum(); ++i)
		{
			res.push_back(make_pair(itr->getKeyValue(i),itr->getData(i)));
		}
		itr = itr->getRightSibling();
	}
	return res;
}

bool BPlusTree::r_search(Node *pNode, KeyType key)const
{
	if (pNode == NULL)  //检测节点指针是否为空,或该节点是否为叶子节点
	{
		return false;
	}
	else
	{
		int keyIndex = pNode -> getKeyIndex(key);
		int childIndex = pNode -> getChildIndex(key, keyIndex); // 孩子结点指针索引
		if (keyIndex< pNode -> getKeyNum() && key == pNode -> getKeyValue(keyIndex))
		{
			return true;
		}
		else
		{
			if (pNode -> getType() == LEAF)   //检查该节点是否为叶子节点
			{
				return false;
			}
			else
			{
				return r_search(((InternalNode*)pNode) -> getChild(childIndex), key);
			}
		}
	}
}

void BPlusTree::print()const
{
	printInConcavo(pRoot, 10);
}

void BPlusTree::printInConcavo(Node *pNode, int count) const {
	if (pNode != NULL)
	{
		int i, j;
		for (i = 0; i< pNode -> getKeyNum(); ++i)
		{
			if (pNode -> getType() != LEAF)
			{
				printInConcavo(((InternalNode*)pNode) -> getChild(i), count - 2);
			}
			for (j = count; j>= 0; --j)
			{
				cout << "-";
			}
			cout << pNode -> getKeyValue(i) << endl;
		}
		if (pNode -> getType() != LEAF)
		{
			printInConcavo(((InternalNode*)pNode) -> getChild(i), count - 2);
		}
	}
}

void BPlusTree::printData()const
{
	LeafNode* itr = pDataHead;
	while (itr != NULL)
	{
		for (int i = 0; i< itr -> getKeyNum(); ++i)
		{
			cout << itr -> getData(i) << " ";
		}
		cout << endl;
		itr = itr -> getRightSibling();
	}
}

bool BPlusTree::remove(KeyType key)
{
	if (!search(key))  //不存在
	{
		return false;
	}
	if (pRoot -> getKeyNum() == 1)//特殊情况处理
	{
		if (pRoot -> getType() == LEAF)
		{
			clear();
			return true;
		}
		else
		{
			Node *pChild1 = ((InternalNode*)pRoot) -> getChild(0);
			Node *pChild2 = ((InternalNode*)pRoot) -> getChild(1);
			if (pChild1 -> getKeyNum() == MINNUM_KEY && pChild2 -> getKeyNum() == MINNUM_KEY)
			{
				pChild1 -> mergeChild(pRoot, pChild2, 0);
				delete pRoot;
				pRoot = pChild1;
			}
		}
	}
	r_remove(pRoot, key);
	return true;
}

// parentNode中包含的键值数>MINNUM_KEY
void BPlusTree::r_remove(Node* parentNode, KeyType key)
{
	int keyIndex = parentNode -> getKeyIndex(key);
	int childIndex = parentNode -> getChildIndex(key, keyIndex); // 孩子结点指针索引
	if (parentNode -> getType() == LEAF)// 找到目标叶子节点
	{
		if (key == MaxKey&&keyIndex> 0)
		{
			MaxKey = parentNode -> getKeyValue(keyIndex - 1);
		}
		parentNode -> removeKey(keyIndex, childIndex);  // 直接删除
															// 如果键值在内部结点中存在,也要相应的替换内部结点
		if (childIndex == 0 && pRoot -> getType() != LEAF && parentNode != pDataHead)
		{
			changeKey(pRoot, key, parentNode -> getKeyValue(0));
		}
	}
	else // 内结点
	{
		Node *pChildNode = ((InternalNode*)parentNode) -> getChild(childIndex); //包含key的子树根节点
		if (pChildNode -> getKeyNum() == MINNUM_KEY)                       // 包含关键字达到下限值,进行相关操作
		{
			Node *pLeft = childIndex> 0 ? ((InternalNode*)parentNode) -> getChild(childIndex - 1) : NULL;                       //左兄弟节点
			Node *pRight = childIndex< parentNode -> getKeyNum() ? ((InternalNode*)parentNode) -> getChild(childIndex + 1) : NULL;//右兄弟节点
																																			 // 先考虑从兄弟结点中借
			if (pLeft && pLeft -> getKeyNum()> MINNUM_KEY)// 左兄弟结点可借
			{
				pChildNode -> borrowFrom(pLeft, parentNode, childIndex - 1, LEFT);
			}
			else if (pRight && pRight -> getKeyNum()> MINNUM_KEY)//右兄弟结点可借
			{
				pChildNode -> borrowFrom(pRight, parentNode, childIndex, RIGHT);
			}
			//左右兄弟节点都不可借,考虑合并
			else if (pLeft)                    //与左兄弟合并
			{
				pLeft -> mergeChild(parentNode, pChildNode, childIndex - 1);
				pChildNode = pLeft;
			}
			else if (pRight)                   //与右兄弟合并
			{
				pChildNode -> mergeChild(parentNode, pRight, childIndex);
			}
		}
		r_remove(pChildNode, key);
	}
}

void BPlusTree::changeKey(Node *pNode, KeyType oldKey, KeyType newKey)
{
	if (pNode != NULL && pNode -> getType() != LEAF)
	{
		int keyIndex = pNode -> getKeyIndex(oldKey);
		if (keyIndex< pNode -> getKeyNum() && oldKey == pNode -> getKeyValue(keyIndex))  // 找到
		{
			pNode -> setKeyValue(keyIndex, newKey);
		}
		else   // 继续找
		{
			changeKey(((InternalNode*)pNode) -> getChild(keyIndex), oldKey, newKey);
		}
	}
}

bool BPlusTree::update(KeyType oldKey, KeyType newKey)
{
	if (search(newKey)) // 检查更新后的键是否已经存在
	{
		return false;
	}
	else
	{
		DataType dataValue;
		remove(oldKey, dataValue);
		if (dataValue == INVALID_INDEX)
		{
			return false;
		}
		else
		{
			return insert(newKey, dataValue);
		}
	}
}

void BPlusTree::remove(KeyType key, DataType& dataValue)
{
	if (!search(key))  //不存在
	{
		dataValue = INVALID_INDEX;
		return;
	}
	if (pRoot -> getKeyNum() == 1)//特殊情况处理
	{
		if (pRoot -> getType() == LEAF)
		{
			dataValue = ((LeafNode*)pRoot) -> getData(0);
			clear();
			return;
		}
		else
		{
			Node *pChild1 = ((InternalNode*)pRoot) -> getChild(0);
			Node *pChild2 = ((InternalNode*)pRoot) -> getChild(1);
			if (pChild1 -> getKeyNum() == MINNUM_KEY && pChild2 -> getKeyNum() == MINNUM_KEY)
			{
				pChild1 -> mergeChild(pRoot, pChild2, 0);
				delete pRoot;
				pRoot = pChild1;
			}
		}
	}
	r_remove(pRoot, key, dataValue);
}

void BPlusTree::r_remove(Node* parentNode, KeyType key, DataType& dataValue)
{
	int keyIndex = parentNode -> getKeyIndex(key);
	int childIndex = parentNode -> getChildIndex(key, keyIndex); // 孩子结点指针索引
	if (parentNode -> getType() == LEAF)// 找到目标叶子节点
	{
		if (key == MaxKey&&keyIndex> 0)
		{
			MaxKey = parentNode -> getKeyValue(keyIndex - 1);
		}
		dataValue = ((LeafNode*)parentNode) -> getData(keyIndex);
		parentNode -> removeKey(keyIndex, childIndex);  // 直接删除
															// 如果键值在内部结点中存在,也要相应的替换内部结点
		if (childIndex == 0 && pRoot -> getType() != LEAF && parentNode != pDataHead)
		{
			changeKey(pRoot, key, parentNode -> getKeyValue(0));
		}
	}
	else // 内结点
	{
		Node *pChildNode = ((InternalNode*)parentNode) -> getChild(childIndex); //包含key的子树根节点
		if (pChildNode -> getKeyNum() == MINNUM_KEY)                       // 包含关键字达到下限值,进行相关操作
		{
			Node *pLeft = childIndex> 0 ? ((InternalNode*)parentNode) -> getChild(childIndex - 1) : NULL;                       //左兄弟节点
			Node *pRight = childIndex< parentNode -> getKeyNum() ? ((InternalNode*)parentNode) -> getChild(childIndex + 1) : NULL;//右兄弟节点
																																			 // 先考虑从兄弟结点中借
			if (pLeft && pLeft -> getKeyNum()> MINNUM_KEY)// 左兄弟结点可借
			{
				pChildNode -> borrowFrom(pLeft, parentNode, childIndex - 1, LEFT);
			}
			else if (pRight && pRight -> getKeyNum()> MINNUM_KEY)//右兄弟结点可借
			{
				pChildNode -> borrowFrom(pRight, parentNode, childIndex, RIGHT);
			}
			//左右兄弟节点都不可借,考虑合并
			else if (pLeft)                    //与左兄弟合并
			{
				pLeft -> mergeChild(parentNode, pChildNode, childIndex - 1);
				pChildNode = pLeft;
			}
			else if (pRight)                   //与右兄弟合并
			{
				pChildNode -> mergeChild(parentNode, pRight, childIndex);
			}
		}
		r_remove(pChildNode, key, dataValue);
	}
}

vector< DataType> BPlusTree::select(KeyType compareKey, int compareOpeartor)
{
	vector< DataType> results;
	if (pRoot != NULL)
	{
		if (compareKey> MaxKey)   // 比较键值大于B+树中最大的键值
		{
			if (compareOpeartor == LE || compareOpeartor == LT)
			{
				for (LeafNode* itr = pDataHead; itr != NULL; itr = itr -> getRightSibling())
				{
					for (int i = 0; i< itr -> getKeyNum(); ++i)
					{
						results.push_back(itr -> getData(i));
					}
				}
			}
		}
		else if (compareKey< pDataHead -> getKeyValue(0))  // 比较键值小于B+树中最小的键值
		{
			if (compareOpeartor == BE || compareOpeartor == BT)
			{
				for (LeafNode* itr = pDataHead; itr != NULL; itr = itr -> getRightSibling())
				{
					for (int i = 0; i< itr -> getKeyNum(); ++i)
					{
						results.push_back(itr -> getData(i));
					}
				}
			}
		}
		else  // 比较键值在B+树中
		{
			SelectResult result;
			search(compareKey, result);
			switch (compareOpeartor)
			{
			case LT:
			case LE:
			{
				LeafNode* itr = pDataHead;
				int i;
				while (itr != result.targetNode)
				{
					for (i = 0; i< itr -> getKeyNum(); ++i)
					{
						results.push_back(itr -> getData(i));
					}
					itr = itr -> getRightSibling();
				}
				for (i = 0; i< result.keyIndex; ++i)
				{
					results.push_back(itr -> getData(i));
				}
				if (itr -> getKeyValue(i)< compareKey ||
					(compareOpeartor == LE && compareKey == itr -> getKeyValue(i)))
				{
					results.push_back(itr -> getData(i));
				}
			}
			break;
			case EQ:
			{
				if (result.targetNode -> getKeyValue(result.keyIndex) == compareKey)
				{
					results.push_back(result.targetNode -> getData(result.keyIndex));
				}
			}
			break;
			case BE:
			case BT:
			{
				LeafNode* itr = result.targetNode;
				if (compareKey< itr -> getKeyValue(result.keyIndex) ||
					(compareOpeartor == BE && compareKey == itr -> getKeyValue(result.keyIndex))
					)
				{
					results.push_back(itr -> getData(result.keyIndex));
				}
				int i;
				for (i = result.keyIndex + 1; i< itr -> getKeyNum(); ++i)
				{
					results.push_back(itr -> getData(i));
				}
				itr = itr -> getRightSibling();
				while (itr != NULL)
				{
					for (i = 0; i< itr -> getKeyNum(); ++i)
					{
						results.push_back(itr -> getData(i));
					}
					itr = itr -> getRightSibling();
				}
			}
			break;
			default:  // 范围查询
				break;
			}
		}
	}
	sort< vector< DataType> ::iterator> (results.begin(), results.end());
	return results;
}

vector< DataType> BPlusTree::select(KeyType smallKey, KeyType largeKey)
{
	vector< DataType> results;
	if (smallKey <= largeKey)
	{
		SelectResult start, end;
		search(smallKey, start);
		search(largeKey, end);
		LeafNode* itr = start.targetNode;
		int i = start.keyIndex;
		if (itr -> getKeyValue(i)< smallKey)
		{
			++i;
		}
		if (end.targetNode -> getKeyValue(end.keyIndex)> largeKey)
		{
			--end.keyIndex;
		}
		while (itr != end.targetNode)
		{
			for (; i< itr -> getKeyNum(); ++i)
			{
				results.push_back(itr -> getData(i));
			}
			itr = itr -> getRightSibling();
			i = 0;
		}
		for (; i <= end.keyIndex; ++i)
		{
			results.push_back(itr -> getData(i));
		}
	}
	sort< vector< DataType> ::iterator> (results.begin(), results.end());
	return results;
}

void BPlusTree::search(KeyType key, SelectResult& result)
{
	r_search(pRoot, key, result);
}

void BPlusTree::r_search(Node* pNode, KeyType key, SelectResult& result)
{
	int keyIndex = pNode -> getKeyIndex(key);
	int childIndex = pNode -> getChildIndex(key, keyIndex); // 孩子结点指针索引
	if (pNode -> getType() == LEAF)
	{
		result.keyIndex = keyIndex;
		result.targetNode = (LeafNode*)pNode;
		return;
	}
	else
	{
		return r_search(((InternalNode*)pNode) -> getChild(childIndex), key, result);
	}
}