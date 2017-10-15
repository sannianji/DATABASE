#pragma once
#ifndef __CHAIN_H
#define __CHAIN_H
#include "linearList.h"

template<typename T>
struct chainNode
{
	T element;
	chainNode<T> *next;

	chainNode() {}
	chainNode(const T& element) { this->element = element; }
	chainNode(const T& element, chainNode<T>* next) { this->element; this->next = next; }

};
template<typename T>
class chain :public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();
//ADT
	bool empty()const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out)const;
	class iterator
	{
	public:
		iterator(chainNode<T>* theNode = NULL) { node = theNode; }
		T& operator*() const { return node->element; }
		T* operator->() { return &node->element; }

		iterator& operator++() { node->next; return *this; }
		iterator& operator++(int) { iterator old = node; node = node->next; return old; }

		bool operator!=(const iterator right) const
		{
			return node != right.node;
		}
		bool operator==(const iterator right) const
		{
			return node == right.node;
		}
	protected:
		chainNode<T>* node;
	};

	void binSort(int range);
protected:
	void checkIndex(int theIndex)const;
	chainNode<T>* firstNode;
	int listSize;
};
template<typename T>
void chain<T>::binSort(int range)
{
	chainNode<T> **bottom, **top;
	bottom = new chainNode<T>*[range + 1];
	top = new chainNode<T>*[range + 1];
	for (int b = 0; b <= range; b++)
		bottom[b] = NULL;

	for (; firstNode != NULL; firstNode = firstNode->next)
	{
		int theBin = firstNode->element;
		if (bottom[theBin] == NULL)
			bottom[thBin] = top[thebin] = firstNode;
		else
		{
			top[theBin]->next = firstNode;
			top[theBin] = firstNode;
		}
	}
	chainNode<T>*y = NULL;
	for(int theBin=0;theBin<=range;theBin++)
		if (bottom[theBin] != NULL)
		{
			if (y == NULL)
				firstNode = bottom[theBin];
			else
				y->next = bottom[theBin];
			y = top[theBin];
		}
	if (y != NULL)
		y->next = NULL;
	delete[] bottom;
	delete[] top;
}
template<typename T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << intialCapacity << " Must be > 0 ";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}
template<typename T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainnode<T>* targetNode = firstNode;
	while (souceNode != NULL)
	{
		targetNode->next = new chaiNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}
template<typename T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
template<typename T>
T& chain<T>::get(int theIndex)const
{
	checkIndex(theIndex);

	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		currentNode = currentNode->next;
	return currentNode->element;
}
template<class T>
int chain<T>::indexOf(const T& theElement)const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != NULL&&currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == NULL)
		return -1;
	else
		return index;
}
template<typename T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);

	chainNode<T>* deleteNode = firstNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i != theIndex - 1; i++)
			currentNode = currentNode->next;

		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}
template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		std::ostringstream s;
		s << "Index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex; i++)
			p = p->next;

		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}
template<typename T>
void chain<T>::output(std::ostream& out) const
{
	for (chainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
	{
		out << currentNode->element << " ";
	}
}
template<typename T>
std::ostream& operator<<(std::ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}
template<typename T>
void chain<T>::checkIndex(int theIndex)const
{
	if (theIndex<0 || theIndex>listSize)
	{
		std::ostringstream s;
		s << " index = " << theIndex << " chain size = " << listSize;
		throw illagelIndex(s.str());
	}
}
template<typename T>
class circularListWithHeader :public linearList<T>
{
public:
	circularListWithHeader();
	int indexOf(const T& theElement)const;
	bool empty()const override { return listSize == 0; }
	int size()const override { return listSize; }
	T& get(int theIndex)const override;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement)override;
	void output(std::ostream& out)const;
private:
	void checkedIndex(int theIndex)const;
	chainNode<T>* headerNode;
	int listSize;
};
template<typename T>
circularListWithHeader<T>::circularListWithHeader()
{
	headerNode = NULL;
	headerNode->next = headerNode;
	listSize = 0;
}
template<typename T>
int circularListWithHeader<T>::indexOf(const T& theElement)const
{
	//headerNode->element = theElement;
	if (theElement == headerNode->element)
		return 0; 
	chainNode<T>* currentNode = headerNode->next;
	int index = 1;
	while ((currentNode->element != theElement)&&(currentNode!=headerNode))
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == headerNode)
		return -1;
	else
		return index;
};
template<typename T>
T& circularListWithHeader<T>::get(int theIndex)const
{
	checkedIndex(theIndex);
	chainNode<T> currentNode=headerNode;
	for (; theIndex != 0; theIndex--)
		currentNode = currentNode->next;
	return currentNode->element;
}
template<typename T>
void circularListWithHeader<T>::checkedIndex(int theIndex) const
{
	if (theIndex<0 || theIndex>listSize)
	{
		std::ostringstream s;
		s << "the index is " << theIndex << " must be >0 && < list size";
		throw illegalIndex(s.str());
	}
	return;
}
template<typename T>
void circularListWithHeader<T>::erase(int theIndex)
{
	checkedInde(theIndex);
	chainNode<T> *currentNode = headerNode;
	if (theIndex == 0)//erase the headerNode
	{
		while (currentNode->next != headerNode)
			currentNode = currentNode->next;
		currentNode->next = headerNode->next;
		headerNode->element.~T();
		delete headerNode;
		headerNode = currentNode->next;
		listSize--;
		return;
	}
	for (; theIndex != 1; theIndex--)//get the pre node
		currentNode = currentNode->next;
	chainNode<T> *theEraseOne = currentNode->next;
	currentNode->next = theEraseOne->next;
	theEraseOne->element.~T();
	delete theEraseOne;
	listSize--;
	return;
}
template<typename T>
void circularListWithHeader<T>::insert(int theIndex, const T& theElement)
{
	checkedIndex(theIndex);
	if(theIndex==0)
}
#endif
