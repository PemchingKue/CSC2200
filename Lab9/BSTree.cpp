//Pemching Kue
//fr6680
#include "BSTree.h"

using namespace std;

template<typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;
}

template<typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree()
{
	root = NULL;
}

template<typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree(const BSTree<DataType, KeyType>& other)
{
	*this = other;
}


template<typename DataType, class KeyType>
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>::operator=(
	const BSTree<DataType, KeyType>& other)
{
	if (*this == &other)
		return *this;
	clear();
	copyTreeHelper(root, other.root);
	return *this;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyTreeHelper(BSTreeNode*& p, BSTreeNode* other)
{
	if (other != NULL)
	{
		BSTreeNode *left = NULL;
		BSTreeNode *right = NULL;
		copyTreeHelper(left, other->left);
		copyTreeHelper(right, other - right);
		p = new BSTreeNode(other->dataItem, left, right);
	}
}

template<typename DataType, class KeyType>
BSTree<DataType, KeyType>::~BSTree()
{
	clear();
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insert(const DataType& newDataItem)
{
	insertHelper(newDataItem, root);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insertHelper(const DataType& newDataItem,
	BSTreeNode*& p)
{
	if (p == NULL)
	{
		p = new BSTreeNode(newDataItem, NULL, NULL);
	}
	else
	{
		if ((p->dataItem).getKey() == newDataItem.getKey())
			p->dataItem = newDataItem;
		else if ((p->dataItem).getKey() > newDataItem.getKey())
			insertHelper(newDataItem, p->left);
		else
			insertHelper(newDataItem, p->right);
	}
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::retrieve(const KeyType& searchKey,
	DataType& searchDataItem) const
{
	return retrieveHelper(searchKey, searchDataItem, root);
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::retrieveHelper(const KeyType& searchKey,
	DataType& searchDataItem, BSTreeNode* p) const
{
	if (p != NULL)
	{
		if (searchKey == (p->dataItem).getKey())
		{
			searchDataItem = p->dataItem;
			return true;
		}
		else if (searchKey < (p->dataItem).getKey())
			return retrieveHelper(searchKey, searchDataItem, p->left);
		else
			return retrieveHelper(searchKey, searchDataItem, p->right);
	}
	else
		return false;
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	return removeHelper(deleteKey, root);
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::removeHelper(const KeyType& deleteKey,
	BSTreeNode*& p)
{
	if (p != NULL)
	{
		if (deleteKey == (p->dataItem).getKey())
		{
			if (p->left == NULL && p->right == NULL)
			{
				delete p;
				p = NULL;
			}
			else if (p->left == NULL)
			{
				BSTreeNode* temp = p;
				p = p->right;
				delete temp;
			}
			else if (p->right == NULL)
			{
				BSTreeNode* temp = p;
				p = p->left;
				delete temp;
			}
			else
			{
				BSTreeNode* temp = p->left;
				while (temp->right != NULL)
					temp = temp->right;
				p->dataItem = temp->dataItem;
				removeHelper((temp->dataItem).getKey(), p->left);
			}
			return true;
		}
		else if (deleteKey < (p->dataItem).getKey())
			return removeHelper(deleteKey, p->left);
		else
			return removeHelper(deleteKey, p->right);
	}
	else
		return false;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeys() const
{
	writeKeysHelper(root);
	cout << endl;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode* p) const
{
	if (p != NULL)
	{
		writeKeysHelper(p->left);
		cout << (p->dataItem).getKey() << " ";
		writeKeysHelper(p->right);
	}
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clear()
{
	clearHelper(root);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clearHelper(BSTreeNode*& p)
{
	if (p != NULL)
	{
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
		if (p->left != NULL)
			p->left = NULL;
		if (p->right != NULL)
			p->right = NULL;
		p = NULL;
	}
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::isEmpty() const
{
	return (root == NULL);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeight() const
{
	return getHeightHelper(root, 0);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeightHelper(BSTreeNode* p,
	int currentLevel) const
{
	static int maxLevel = 0;
	if (p == NULL)
	{
		if (currentLevel > maxLevel)
			maxLevel = currentLevel;
	}
	else
	{
		getHeightHelper(p->left, currentLevel + 1);
		getHeightHelper(p->right, currentLevel + 1);
	}
	return maxLevel;
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCount() const
{
	return getCountHelper(root);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCountHelper(BSTreeNode* p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + getCountHelper(p->left) + getCountHelper(p->right);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLessThan(const KeyType& searchKey) const
{
	if (isEmpty())  {
		cout << "Tree is empty!" << endl;
	}
	else  {
		writeLTHelper(root, searchKey);
	}
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLTHelper(BSTreeNode* p, KeyType searchKey) const
{
	if (p != NULL)  {
		if (p->dataItem.getKey() >= searchKey)  {
			writeLTHelper(p->left, searchKey);
		}
		else  {
			writeKeysHelper(p->left);
			cout << p->dataItem.getKey() << endl;
			writeLTHelper(p->right, searchKey);
		}
	}
}

#include "show9.cpp"