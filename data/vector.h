#pragma once
#ifndef __VECTOR_H
#define __VECTOR_H
#include "linearList.h"
#include <vector>

template <typename T>
class vectorList :public linearList<T>
{
public:
	vectorList(int initialCapacity = 10);
	vectorList(const vectorList<T> &);
	~vectorList() override { delete element; }

	bool empty()const override{ return element->empty(); }
	int size()const override{ return (int)element->size(); }
	T& get(int theIndex)const override;
	int indexOf(const T & theElement)const override;
	void erase(int theIndex) override;
	void insert(int theIndex, const T& theElement) override;
	void output(std::ostream& os)const override;

	int capacity() const{ return (int)element->capacity(); }

	typedef typename std::vector<T>::iterator iterator;
	iterator begin() { return element->begin(); }
	iterator end() { return element->end(); }

protected:
	void checkIndex(int theIndex)const;
	std::vector<T>* element;
};
template<typename T>
vectorList<T>::vectorList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity =" << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	element = new std::vector<T>;
	element->reserve(initialCapacity);
}
template<typename T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{
	element = new std::vector<T>(*theList.element);
}
template<typename T>
void vectorList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	element->erase(begin() + theIndex);
}
template<typename T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>size())
	{//illegal index
		std::ostringstream s;
		s << "Index = " << theIndex << " size = " << size();
		throw illegalIndex(s.str());
	}
	element->insert(element->begin() + theIndex, theElement);
}
template<typename T>
T& vectorList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element->at(theIndex);
}
template<typename T>
void vectorList<T>::checkIndex(int theIndex)const
{
	if (theIndex<0 || theIndex>=element->size())
	{
		std::ostringstream s;
		s << "Index = " << theIndex << " size = " << element->size();
		throw illegalIndex(s.str());
	}
}
template<typename T>
int vectorList<T>::indexOf(const T& theElement)const
{
	for (int i = 0; i < (int)(element->size()); i++)
		if ((*element)[i] == theElement)
			return i;
	return -1;
}
template<typename T>
void vectorList<T>::output(std::ostream& os)const
{
	for (auto a : (*element))
		os << a << "\t";
}
#endif