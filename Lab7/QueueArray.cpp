//Pemching Kue
//fr6680
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
	dataItems = new DataType[maxNumber];
	maxSize = maxNumber;
	front = 0;
	back = 0;
}

template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
	this = other;
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
	if (*this == other)
		return *this;
	else
	{
		maxSize = other.maxSize;
		front = other.front;
		back = other.back;
		dataItems = new DataType[maxSize];
		for (int i = 0; i < maxSize; i++)
			dataItems[i] = other.dataItems[i];
		return *this;
	}
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
	delete[]dataItems;
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if ((front == back) && (back == 0))
	{
		dataItems[back] = newDataItem;
		back++;
	}
	else if (back < maxSize)
	{
		dataItems[back] = newDataItem;
		back++;
	}
	else if (back > maxSize)
	{
		back = 0;
		if (front == 0)
		{
			throw("List Full!\n");
		}
		else
		{
			dataItems[back] = newDataItem;
		}
		back++;
	}
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
	if (dataItems[front] == NULL)
		throw("list empty!\n");
	else if (front < maxSize)
	{
		DataType temp = dataItems[front];
		dataItems[front] = NULL;
		front++;
		return temp;
	}
	else if (front>maxSize)
	{
		front = 0;
		DataType temp = dataItems[front];
		dataItems[front] = NULL;
		return temp;
	}
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
	for (int i = 0; i < maxSize; i++)
		dataItems[i] = NULL;
	front = 0;
	back = 0;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
	return dataItems[front] == NULL;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
	return (back == front && dataItems[front] != NULL);
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if ((back) == 0)
	{
		if (front == 0)
		{
			dataItems[front] = newDataItem;
		}
		else if ((front - 1) == back)
		{
			throw("list full\n");
		}
		else
		{
			front--;
			dataItems[front] = newDataItem;
		}
	}
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
	if (dataItems[back] == NULL)
		throw("List is either full or empty!\n");
	else
	{
		DataType temp = dataItems[back];
		dataItems[back] = NULL;
		if (back == 0)
			back = maxSize - 1;
		else
			back--;
		return temp;
	}
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
	int count = 0;
	if (back > front){
		for (int i = front; i < back; i++)
			count++;
	}
	else
	{
		for (int i = front; i < maxSize; i++)
			count++;
		for (int i = 0; i < back; i++)
			count++;
	}
	return count;
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}