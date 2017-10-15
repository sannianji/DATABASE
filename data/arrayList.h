#ifndef __ARRAYLIST_H
#define __ARRAYLIST_H
#include "linearList.h"
//#include <iostream>
#include <algorithm>
#include <iterator>
template<typename T>
class arrayList:public linearList<T>
{
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() override{ delete[] element; }

	//ADT
	bool empty() const override { return listSize == 0; }
	int size() const override{ return listSize; }

	T& get(int theIndex) const override;
	int indexOf(const T& theElement)const override;
	void erase(int theIndex) override;
	void insert(int theIndex, const T& theElement)override;
	void output(std::ostream& out)const override;
	
	void trimToSize(int newSize);
	void setSize(int newSize);

	T& operator[](int theIndex)const;
	bool operator==(const arrayList<T>& theArray)const;
	bool operator!=(const arrayList<T>& theArray)const;
	
	void swap(arrayList<T>& theArray);
	void push_back(const T& theElement);
	T pop_back();
protected:
	void checkIndex(int theIndex)const;
	T* element;
	int arrayLength;//capacity
	int listSize;//numbers
};
template<typename T>
T arrayList<T>::pop_back()
{
	T theReturn = *(this->elemen + listSize);
	*(this->element + listSize).~T();
	listSize--;
	return theReturn;//发生拷贝两次，应当使用move，返回右值引用
}
template<typename T>
void arrayList<T>::swap(arrayList<T>& theArray)
{
	T* tempPointer = theArray.element;
	theArray.element = this->element;
	this->element = tempPointer;

	int tempLength = theArray.arrayLength;
	theArray.arrayLength = this->arrayLength;
	this->arrayLength = tempLength;

	int tempSize = theArray.listSize;
	theArray.listSize = this->listSize;
	this->listSize = tempSize;
}
template<typename T>
void arrayList<T>::push_back(const T& theElement)
{
	if (arrayLength == listSize)
		changeLength1D(this->element, arrayLength, arrayLength * 2);
	*(this->element + listSize) = theElement;
	listSize++;
	return;
}
template<typename T>
bool arrayList<T>::operator!=(const arrayList<T>& theArray)const
{
	if (*this == theArray)
		return false;
	else
		return true;
}
template<typename T>
bool arrayList<T>::operator==(const arrayList<T>& theArray)const
{
	if (this->listSize != theArray.listSize)
		return false;
	for (int i = 0; i != this->listSize; i++)
		if (*(this->element + i) != *(theArray.element + i))
			return false;
	return true;
}
template<typename T>
T& arrayList<T>::operator[](int theIndex)const
{
	checkIndex(theIndex);
	return *(this->element + theIndex);
}
template<typename T>
void arrayList<T>::setSize(int newSize)
{
	if (newSize < 0)
	{
		std::ostringstream s;
		s << "the new size must be >0";
		throw illegalParameterValue(s.str());
	}
	if (newSize < listSize)
	{
		for (; newSize != listSize; newSize++)
			this->element[newSize].~T();
		listSize = newSize;
	}
	if (newSize > arrayLength)
		changeLength1D(this->element, arrayLength, newLength);
	listSize = newSize;
	return;
}
template<typename T>
void arrayList<T>::trimToSize(int newSize)
{
	int size = max(newSize, 1);
	if (size>listSize)
	{
		std::ostringstream s;
		s << "the new listSize must be > 0 and < listSize ";
		throw illegalParameterValue(s.str());
	}
	if (size == listSize)
		return;
	else
	{
		for (; size != listSize; size++)
			this->element[size].~T();
		listSize = size;
	}
}
template<typename T>
arrayList<T>::arrayList(int initialCapacity)
{
	if (initialCapacity < 0)
	{
		std::ostringstream s;
		s << "Initial Capacity = " << initialCapacity << " must be > 0";
		throw illegalParameterValue(s.str());
	}

	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}
template<typename T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	element = new T[arrayLength];
	listSize = theList.listSize;
	copy(theList.element, theList.element + theList.listSize, element);
}
template<typename T>
void arrayList<T>::checkIndex(int theIndex)const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		std::ostringstream s;
		s << "Index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
}
template<typename T>
T& arrayList<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	return element[theIndex];
}
template<typename T>
int arrayList<T>::indexOf(const T& theElement)const
{
	//return the first time of theElement
	//if could't find theElement,return -1
	int theIndex = (int)(std::find(element, element + listSize, theElement) - element);

	if (theIndex == listSize)
		return -1;
	else
		return theIndex;
}
template<class T>
void arrayList<T>::output(std::ostream& out)const
{
	for (int i = 0; i != listSize; i++)
		out << element[i] << " ";
}
template<typename T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x)
{
	x.output(out); 
	return out;
}
template<typename T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element + theIndex, element + listSize, element + theIndex);
	element[--listSize].~T();
}
template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str());
	}
	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}
#endif