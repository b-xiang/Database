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

bool BPlusTree::insert(BPTKeyType key, const BPTDataType& data) {
	// �Ƿ��Ѿ�����
	if (search(key))
	{
		return false;
	}
	// �ҵ����Բ����Ҷ�ӽ��,���򴴽��µ�Ҷ�ӽ��
	if (pRoot == NULL)
	{
		pRoot = new LeafNode();
		pDataHead = (LeafNode*)pRoot;
		MaxKey = key;
	}
	if (pRoot -> getKeyNum()>= MAXNUM_KEY) // ���������,����
	{
		InternalNode* newNode = new InternalNode();  //�����µĸ��ڵ�
		newNode -> setChild(0, pRoot);
		pRoot -> split(newNode, 0);    // Ҷ�ӽ�����
		pRoot = newNode;  //���¸��ڵ�ָ��
	}
	if (key> MaxKey)  // ��������ֵ
	{
		MaxKey = key;
	}
	r_insert(pRoot, key, data);
	return true;
}

void BPlusTree::r_insert(Node* parentNode, BPTKeyType key, const BPTDataType& data)
{
	if (parentNode -> getType() == LEAF)  // Ҷ�ӽ��,ֱ�Ӳ���
	{
		((LeafNode*)parentNode) -> insert(key, data);
	}
	else
	{
		// �ҵ��ӽ��
		int keyIndex = parentNode -> getKeyIndex(key);
		int childIndex = parentNode -> getChildIndex(key, keyIndex); // ���ӽ��ָ������
		Node* childNode = ((InternalNode*)parentNode) -> getChild(childIndex);
		if (childNode -> getKeyNum()>= MAXNUM_LEAF)  // �ӽ������,����з���
		{
			childNode -> split(parentNode, childIndex);
			if (parentNode -> getKeyValue(childIndex) <= key)   // ȷ��Ŀ���ӽ��
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

bool BPlusTree::search(BPTKeyType key)
{
	return r_search(pRoot, key);
}

vector<BPTDataType> BPlusTree::getAllValues()
{
	vector<BPTDataType> res;
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

vector<pair<BPTKeyType, BPTDataType>> BPlusTree::getAllKVPairs()
{
	vector<pair<BPTKeyType,BPTDataType> > res;
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

bool BPlusTree::r_search(Node *pNode, BPTKeyType key)const
{
	if (pNode == NULL)  //���ڵ�ָ���Ƿ�Ϊ��,��ýڵ��Ƿ�ΪҶ�ӽڵ�
	{
		return false;
	}
	else
	{
		int keyIndex = pNode -> getKeyIndex(key);
		int childIndex = pNode -> getChildIndex(key, keyIndex); // ���ӽ��ָ������
		if (keyIndex< pNode -> getKeyNum() && key == pNode -> getKeyValue(keyIndex))
		{
			return true;
		}
		else
		{
			if (pNode -> getType() == LEAF)   //���ýڵ��Ƿ�ΪҶ�ӽڵ�
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

bool BPlusTree::remove(BPTKeyType key)
{
	if (!search(key))  //������
	{
		return false;
	}
	if (pRoot -> getKeyNum() == 1)//�����������
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

// parentNode�а����ļ�ֵ��>MINNUM_KEY
void BPlusTree::r_remove(Node* parentNode, BPTKeyType key)
{
	int keyIndex = parentNode -> getKeyIndex(key);
	int childIndex = parentNode -> getChildIndex(key, keyIndex); // ���ӽ��ָ������
	if (parentNode -> getType() == LEAF)// �ҵ�Ŀ��Ҷ�ӽڵ�
	{
		if (key == MaxKey&&keyIndex> 0)
		{
			MaxKey = parentNode -> getKeyValue(keyIndex - 1);
		}
		parentNode -> removeKey(keyIndex, childIndex);  // ֱ��ɾ��
															// �����ֵ���ڲ�����д���,ҲҪ��Ӧ���滻�ڲ����
		if (childIndex == 0 && pRoot -> getType() != LEAF && parentNode != pDataHead)
		{
			changeKey(pRoot, key, parentNode -> getKeyValue(0));
		}
	}
	else // �ڽ��
	{
		Node *pChildNode = ((InternalNode*)parentNode) -> getChild(childIndex); //����key���������ڵ�
		if (pChildNode -> getKeyNum() == MINNUM_KEY)                       // �����ؼ��ִﵽ����ֵ,������ز���
		{
			Node *pLeft = childIndex> 0 ? ((InternalNode*)parentNode) -> getChild(childIndex - 1) : NULL;                       //���ֵܽڵ�
			Node *pRight = childIndex< parentNode -> getKeyNum() ? ((InternalNode*)parentNode) -> getChild(childIndex + 1) : NULL;//���ֵܽڵ�
																																			 // �ȿ��Ǵ��ֵܽ���н�
			if (pLeft && pLeft -> getKeyNum()> MINNUM_KEY)// ���ֵܽ��ɽ�
			{
				pChildNode -> borrowFrom(pLeft, parentNode, childIndex - 1, LEFT);
			}
			else if (pRight && pRight -> getKeyNum()> MINNUM_KEY)//���ֵܽ��ɽ�
			{
				pChildNode -> borrowFrom(pRight, parentNode, childIndex, RIGHT);
			}
			//�����ֵܽڵ㶼���ɽ�,���Ǻϲ�
			else if (pLeft)                    //�����ֵܺϲ�
			{
				pLeft -> mergeChild(parentNode, pChildNode, childIndex - 1);
				pChildNode = pLeft;
			}
			else if (pRight)                   //�����ֵܺϲ�
			{
				pChildNode -> mergeChild(parentNode, pRight, childIndex);
			}
		}
		r_remove(pChildNode, key);
	}
}

void BPlusTree::changeKey(Node *pNode, BPTKeyType oldKey, BPTKeyType newKey)
{
	if (pNode != NULL && pNode -> getType() != LEAF)
	{
		int keyIndex = pNode -> getKeyIndex(oldKey);
		if (keyIndex< pNode -> getKeyNum() && oldKey == pNode -> getKeyValue(keyIndex))  // �ҵ�
		{
			pNode -> setKeyValue(keyIndex, newKey);
		}
		else   // ������
		{
			changeKey(((InternalNode*)pNode) -> getChild(keyIndex), oldKey, newKey);
		}
	}
}

bool BPlusTree::update(BPTKeyType oldKey, BPTKeyType newKey)
{
	if (search(newKey)) // �����º�ļ��Ƿ��Ѿ�����
	{
		return false;
	}
	else
	{
		BPTDataType dataValue;
		remove(oldKey, dataValue);
		/*if (dataValue == INVALID_INDEX)
		{
			return false;
		}
		else
		{*/
			return insert(newKey, dataValue);
		//}
	}
}

void BPlusTree::remove(BPTKeyType key, BPTDataType& dataValue)
{
	if (!search(key))  //������
	{
		dataValue = INVALID_INDEX;
		return;
	}
	if (pRoot -> getKeyNum() == 1)//�����������
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

void BPlusTree::r_remove(Node* parentNode, BPTKeyType key, BPTDataType& dataValue)
{
	int keyIndex = parentNode -> getKeyIndex(key);
	int childIndex = parentNode -> getChildIndex(key, keyIndex); // ���ӽ��ָ������
	if (parentNode -> getType() == LEAF)// �ҵ�Ŀ��Ҷ�ӽڵ�
	{
		if (key == MaxKey&&keyIndex> 0)
		{
			MaxKey = parentNode -> getKeyValue(keyIndex - 1);
		}
		dataValue = ((LeafNode*)parentNode) -> getData(keyIndex);
		parentNode -> removeKey(keyIndex, childIndex);  // ֱ��ɾ��
															// �����ֵ���ڲ�����д���,ҲҪ��Ӧ���滻�ڲ����
		if (childIndex == 0 && pRoot -> getType() != LEAF && parentNode != pDataHead)
		{
			changeKey(pRoot, key, parentNode -> getKeyValue(0));
		}
	}
	else // �ڽ��
	{
		Node *pChildNode = ((InternalNode*)parentNode) -> getChild(childIndex); //����key���������ڵ�
		if (pChildNode -> getKeyNum() == MINNUM_KEY)                       // �����ؼ��ִﵽ����ֵ,������ز���
		{
			Node *pLeft = childIndex> 0 ? ((InternalNode*)parentNode) -> getChild(childIndex - 1) : NULL;                       //���ֵܽڵ�
			Node *pRight = childIndex< parentNode -> getKeyNum() ? ((InternalNode*)parentNode) -> getChild(childIndex + 1) : NULL;//���ֵܽڵ�
																																			 // �ȿ��Ǵ��ֵܽ���н�
			if (pLeft && pLeft -> getKeyNum()> MINNUM_KEY)// ���ֵܽ��ɽ�
			{
				pChildNode -> borrowFrom(pLeft, parentNode, childIndex - 1, LEFT);
			}
			else if (pRight && pRight -> getKeyNum()> MINNUM_KEY)//���ֵܽ��ɽ�
			{
				pChildNode -> borrowFrom(pRight, parentNode, childIndex, RIGHT);
			}
			//�����ֵܽڵ㶼���ɽ�,���Ǻϲ�
			else if (pLeft)                    //�����ֵܺϲ�
			{
				pLeft -> mergeChild(parentNode, pChildNode, childIndex - 1);
				pChildNode = pLeft;
			}
			else if (pRight)                   //�����ֵܺϲ�
			{
				pChildNode -> mergeChild(parentNode, pRight, childIndex);
			}
		}
		r_remove(pChildNode, key, dataValue);
	}
}

vector< BPTDataType> BPlusTree::select(BPTKeyType compareKey, int compareOpeartor)
{
	vector< BPTDataType> results;
	if (pRoot != NULL)
	{
		if (compareKey> MaxKey)   // �Ƚϼ�ֵ����B+�������ļ�ֵ
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
		else if (compareKey< pDataHead -> getKeyValue(0))  // �Ƚϼ�ֵС��B+������С�ļ�ֵ
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
		else  // �Ƚϼ�ֵ��B+����
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
			default:  // ��Χ��ѯ
				break;
			}
		}
	}
	sort< vector< BPTDataType> ::iterator> (results.begin(), results.end());
	return results;
}

vector< BPTDataType> BPlusTree::select(BPTKeyType smallKey, BPTKeyType largeKey)
{
	vector< BPTDataType> results;
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
	sort< vector< BPTDataType> ::iterator> (results.begin(), results.end());
	return results;
}

void BPlusTree::search(BPTKeyType key, SelectResult& result)
{
	r_search(pRoot, key, result);
}

void BPlusTree::r_search(Node* pNode, BPTKeyType key, SelectResult& result)
{
	int keyIndex = pNode -> getKeyIndex(key);
	int childIndex = pNode -> getChildIndex(key, keyIndex); // ���ӽ��ָ������
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