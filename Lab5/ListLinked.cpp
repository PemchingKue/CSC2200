//Pemching Kue
//fr6680

#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename DataType>
List<DataType>::List(int ignored = 0)
{
	head = NULL;
	cursor = NULL;
}

template <typename DataType>
List<DataType>::List(const List& other)
{
	head = 0;
	cursor = 0;
	operator=(other);
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
	if (this == &other)
		return *this;
	else
	{
		clear();
		ListNode* tmph = other->head;
		ListNode* tmp1 = 0;
		while (tmph != 0)
		{
			insert(tmph->dataItem);
			if (tmph == other->cursor)
				tmp1 = other->cursor;
			tmph = tmph->next;
		}
		cursor = tmp1;
		return *this;
	}
}

template <typename DataType>
List<DataType>::~List()
{
	clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	if (head == NULL)
	{
		head = new ListNode(newDataItem, NULL);
		cursor = head;
	}
	else
	{
		//ListNode node =;
		cursor->next = new ListNode(newDataItem, cursor->next);
		cursor = cursor->next;
	}
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	ListNode* tmp;
	if (head == NULL)
		throw("List empty!\n");
	else if (cursor == head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
		cursor = head;
	}
	else if (cursor->next == NULL)
	{
		tmp = cursor;
		cursor = head;
		while (cursor->next != tmp)
			cursor = cursor->next;
		cursor->next = NULL;
		delete tmp;
		cursor = head;
	}
	else
	{
		tmp = cursor->next;
		cursor->dataItem = tmp->dataItem;
		cursor->next = tmp->next;
		delete tmp;
	}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	if (head == NULL)
		throw("List empty!\n");
	cursor->dataItem = newDataItem;
}

template <typename DataType>
void List<DataType>::clear()
{

		cursor = head;
		while (cursor->next != NULL){
			head = cursor->next;
			delete cursor;
			cursor = head;
		}
		delete cursor;
		head = NULL;
		cursor = NULL;

}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	return head == NULL;
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (head == NULL)
		throw("List is empty!\n");
	cursor = head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	if (head == NULL)
		throw("List is empty!\n");
	cursor = head;
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (head == NULL)
		throw("List empty!\n");
	else if (cursor != NULL)
	{
		cursor = cursor->next;
		return true;
	}
	else
		return false;
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if (head == NULL)
		throw("List empty!\n");
	else if (cursor == head)
		return false;
	else
	{
		ListNode* tmp = cursor;
		cursor = head;
		while (cursor->next != tmp)
			cursor = cursor->next;
		return true;
	}
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	if (head == NULL)
		throw("List empty!\n");
	return cursor->dataItem;
}

template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error)
{
	ListNode* tmp = head;
	while (tmp->next != cursor)
		tmp = tmp->next;
	tmp->next = cursor->next;
	cursor->next = head;
	head = cursor;
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
		throw("List empty!\n");
	else if (head == NULL)
	{
		insert(newDataItem);
	}
	else
	{
		ListNode* node = new ListNode(cursor->dataItem, cursor->next);
		cursor->next = node;
		cursor->dataItem = newDataItem;
	}
}

#include "show5.cpp"

