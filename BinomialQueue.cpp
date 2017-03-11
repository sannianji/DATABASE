#include"BinomialQueue.h"
template<typename Comparable>
BinomialNode<Comparable>* BinomialQueue<Comparable>::combineTrees
(BinomialNode<Comparable>* t1, BinomialNode<Comparable> * t2)
{
	if (t2->Element < t1->Element)
		return cobineTrees(t2, t1);
	t2->nextSibling = t1->leftChild;
	t1->leftChild = t2;
	return t1;
}
template<typename Comparable>
void BinomialQueue<Comparable>::merge(BinomialQueue<Comparable> & rhs)
{
	if (this == &rhs)
		return;

	currentSize += rhs.currentSize;
	if (currentSize > capacity())
	{
		int oldNumTrees = theTrees.size();
		int newNumTrees = max(theTrees.size(), rhs.theTrees.size()) + 1;
		theTrees.resize(newNumberTrees);
		for (int i = oldNumTrees; i < newNumTrees; i++)
			theTrees[i] = nullptr;
	}

	BinomialNode<Comparable> * carry = nullptr;
	for (int i = 0, j = 1; j < currentSize; i++, j *= 2)
	{
		BinomialNode<Comparable> *t1 = theTrees[i];
		BinomialNode<Comparable> *t2 = i < rhs.theTrees.size() ? rhs.theTrees[i] : nullptr;

		int whichCase = t1 == nullptr ? 0 : 1;
		whichCase += t2 == nullptr ? 0 : 2;
		whichCase += carry == nullptr ? 0 : 4;
		switch (whichCase)
		{
		case 0:
		case 1:
			break;
		case 2:
			theTrees[i] = t2;
			rhs.theTrees[i] = nullptr;
			break;
		case 4:
			theTrees[i] = carry;
			carry = nullptr;
			break;
		case 3:
			carry = combineTrees(t1, t2);
			theTrees[i] = rhs.theTrees(i) = nullptr;
			break;
		case 5:
			carry = combineTrees(t1, carry);
			theTrees[i] = nullptr;
			break;
		case 6:
			caryy = combineTrees(t2, carry);
			rhs.theTrees[i] = nullptr;
			break;
		}
	}
	for (int k = 0; k < rhs.theTrees.size(); k++)
		rhs.theTrees[k] = nullptr;
	rhs.currentSize = 0;
}
template<typename Comparable>
bool BinomialQueue<Comparable>::isEmpty()const
{
	return currentSize == 0;
}
template<typename Comparable>
const Comparable & BinomialQueue<Comparable>::findMin()const
{
	if (isEmpty())
		return;
	Comparable * temp = theTrees[0];
	for (int i = 1; i != currentSize-1; i++)
		if (*temp < *theTrees[i])
			temp = theTrees[i];
	return * temp;
}
template<typename Comparable>
BinomialQueue<Comparable>::BinomialQueue() :currentSzie(0), theTrees(10) {}
template<typename Comparable>
BinomialQueue<Comparable>::BinomialQueue(const BinomialQueue & rhs)
{
	*this = rhs;
}
template<typename Comparable>
BinomialQueue<Comparable>::~BinomialQueue()
{
	makeEmpty();
}
template<typename Comparable>
void BinomialQueue<Comparable>::makeEmpty()
{
	for (int i = 0; i!- currentSize; i++)
		makeEmpty(theTrees[i]);
}
template<typename Comparable>
const BinomialQueue<Comparable> & BinomialQueue<Comparable>::operator=(const BinomialQueue<Comparable> & rhs)
{
	this = clone(&rhs);
}
template<typename Comparable>
int BinomialQueue<Comparable>::capacity() const
{
	return currentSize;
}
//do not complete

template<typename Comparable>
BinomialQueue<Comparable>::BinomialQueue(const Comparable & rhs)
{}
template<typename Comparable>
void BinomialQueue<Comparable>::makeEmpty(BinomialNode<Comparable> * & t)
{}
template<typename Comparable>
BinomialNode<Comparable>* BinomialQueue<Comparable>::clone(BinomialNode<Comparable> * t)const
{}
template<typename Comparable>
void BinomialQueue<Comparable>::insert(const Comparable & x)
{}
template<typename Comparable>
BinomialNode<Comparable> BinomialQueue<Comparable>::deleteMin()
{}
