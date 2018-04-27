//Pemching Kue
//fr6680
#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber)
{
	top = NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	top = other.top;
	while (top != NULL)
	{
		StackNode node = new StackNode(top->next->dataItem; top->next);
		top = top->next;
	}
	top = other.top;
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	if (*this == other)
		return *this;
	else
	{
		StackNode* temp;
		while (top != NULL)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
		delete top;
		top = new StackNode(other.top->dataItem; other.top->next);
		while (top != NULL)
		{
			StackNode node = new StackNode(top->next->dataItem; top->next);
			top = top->next;
		}
		top = other.top;
		return *this;
	}
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	int count = 0;
	StackNode* temp = top;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count == MAX_STACK_SIZE)
		throw("Cannot hold anymore data!");
	else if (top == NULL)
	{
		top = new StackNode(newDataItem, NULL);
	}
	else
	{
		StackNode* node = new StackNode(top->dataItem, top->next);
		top->dataItem = newDataItem;
		top->next = node;
	}
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	DataType temp = top->dataItem;
	StackNode* tmp = top;
	top = top->next;
	delete tmp;
	return temp;
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode* t;
	while ( top != NULL)
	{
		t = top;
		top = top->next;
		delete t;
	}
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	return (top == NULL);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}