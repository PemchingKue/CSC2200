//Pemching Kue
//fr6680
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE)
{
	front = NULL;
	back = NULL;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
	if (*this == other)
		return *this;
	else
	{
		QueueNode* temp;
		front = new QueueNode(other.front->dataItem, other.front->next;);
		temp = front;
		while (temp != NULL)
		{
			temp = temp->next;
			QueueNode* node = new QueueNode(temp->dataItem, temp->next);
			back = node;
		}
		return *this;
	}
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	if (*this == other)
		return *this;
	else
	{
		clear();
		front = new QueueNode(other.front->dataItem, other.front->next);
		QueueNode* temp = front;
		while (temp != NULL)
		{
			temp = temp->next;
			QueueNode* node = new QueueNode(temp->dataItem, temp->next);
		}
		back = new QueueNode(other.back->dataItem, other.back->next);
	}
	return *this;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (front == NULL)
	{
		front = new QueueNode(newDataItem, NULL);
	}
	else if (back == NULL)
	{
		back = new QueueNode(newDataItem, NULL);
		front->next = back;
	}
	else
	{
		QueueNode* tmp = new QueueNode(newDataItem, NULL);
		back->next = tmp;
		back = tmp;
	}
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	DataType temp;
	if (front == NULL)
		throw("list empty!\n");
	else
	{
		QueueNode* tmp = front;
		temp = front->dataItem;
		front = front->next;
		delete tmp;
	}
	return temp;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	back = NULL;
	QueueNode* tmp;
	while (front->next != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
	delete front;
	delete back;
	front = NULL;
	back = NULL;
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	return (front == NULL);
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	QueueNode* node = new QueueNode(newDataItem, front);
	front = node;
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	DataType temp = back->dataItem;
	QueueNode* tmp = front;
	QueueNode* tmp2;
	while (tmp->next->next != back)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = back;
	back->dataItem = tmp2->dataItem;
	delete tmp2;
	return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	QueueNode* tmp = front;
	int count = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}