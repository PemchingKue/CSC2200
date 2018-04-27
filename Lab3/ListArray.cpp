//Pemching Kue
//fr6680
#include "ListArray.h"

template < typename DataType >
List<DataType>::List(int maxNumber)
{
	maxSize = maxNumber;
	size = 0;
	cursor = -1;
	dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List(const List& source)
{
	size = source.size;
	maxSize = source.maxSize;
	cursor = source.cursor;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < size; i++)
	{
		dataItems[i] = source.dataItems[i];
	}
}

template < typename DataType >
List<DataType>& List<DataType>::operator= (const List& source)
{
	maxSize = source.maxSize;
	size = source.size;
	cursor = source.cursor;
	delete[] dataItems;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < size; i++)
	{
		dataItems[i] = source.dataItems[i];
	}
	return *this;
}

template < typename DataType >
List<DataType>::~List()
{
	delete[] dataItems;
}

template < typename DataType >
void List<DataType>::insert(const DataType& newDataItem)
throw (logic_error)
{
	if (size + 1 == maxSize)
		throw("No more room in array!");
	size++;
	for (int i = size; i > cursor; i--)
	{
		dataItems[i] = dataItems[i - 1];
	}
	dataItems[cursor] = newDataItem;
	cursor++;
}

template < typename DataType >
void List<DataType>::remove() throw (logic_error)
{
	if (size == 0)
		throw logic_error("size == 0\n");

	for (int i = cursor; i < size - 1; i++)
		dataItems[i] = dataItems[i + 1];
	size--;
	if (size == 0)
		cursor = -1;
	else if (size == cursor)
		cursor = 0;

}

template < typename DataType >
void List<DataType>::replace(const DataType& newDataItem)
throw (logic_error)
{
	if (cursor < -1 || cursor > maxSize)
		throw("cursor out of bound");
	if (size == 0)
		throw("array is empty!.\n");

	dataItems[cursor] = newDataItem;
}

template < typename DataType >
void List<DataType>::clear()
{
	size = 0;
	cursor = -1;
}

template < typename DataType >
bool List<DataType>::isEmpty() const
{
	return(size == 0);
}

template < typename DataType >
bool List<DataType>::isFull() const
{
	return(size == maxSize);
}

template < typename DataType >
void List<DataType>::gotoBeginning()
throw (logic_error)
{
	if (size == 0)
		throw("array is empty!");
	else
		cursor = 0;
}

template < typename DataType >
void List<DataType>::gotoEnd()
throw (logic_error)
{
	if (size == 0)
		throw("array is empty!");
	else
		cursor = size - 1;
}

template < typename DataType >
bool List<DataType>::gotoNext()
throw (logic_error)
{
	if (cursor + 1 > maxSize)
	{
		throw("End of array.");
	}
	if (cursor != size - 1)
	{
		cursor++;
		return true;
	}
	else
		return false;
}

template < typename DataType >
bool List<DataType>::gotoPrior()
throw (logic_error)
{
	if (size == 0)
		throw("array empty!");
	if (cursor != 0)
	{
		cursor--;
		return true;
	}
	else
		return false;
}

template < typename DataType >
DataType List<DataType>::getCursor() const
throw (logic_error)
{
	if (size == 0)
		throw("array empty!");
	return dataItems[cursor];
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth(int n)
throw (logic_error)
{
	if (n > maxSize)
		throw("cannot move beyond size of array.");
	DataType hold = dataItems[cursor];
	dataItems[cursor] = dataItems[n];
	dataItems[n] = hold;
}

template < typename DataType >
bool List<DataType>::find(const DataType& searchDataItem)
throw (logic_error)
{
	if (size == 0)
		throw("array empty!");

	for (int i = 0; i < size; i++)
	{
		if (searchDataItem == dataItems[i])
			return true;
	}
	throw("Item not found.");
	return false;
}