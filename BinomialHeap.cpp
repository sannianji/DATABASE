#include"Binomialheap.h"
template<typename Comparable>
BinomialHeap<Comparable>::BinomialHeap(const BinomialHeap<Comparable> & rhs) :currentSize(rhs.currentSize), theHeap(rhs.currentSize, nullptr)
{
	if (rhs.currenSize != 0)
		*this = rhs;
	else
		this.makeEmpty();
	return;
}
template<typename Comparable>
BinomialHeap<Comparable> & BinomialHeap<Comparable>::operator=(const BinomialHeap & rhs)
{
	return rhs.clone();
}
template<typename Comparable>
BinomialHeap<Comparable> & BinomialHeap<Comparable>::clone()
{
	for (int i = currentSize - 1; i != 0; i--)
	{
		if (rhs.theHeap[i] != nullptr)
			theHeap[i] = makeNewBinomialNode(rhs.theHeap[i]);
	}
	theHeap[0] = new BinomialNode<Comparable>(*rhs.theHeap[0]);
	return *this;
}
template<typename Comparable>
BinomialNode<Comparable>* BinomialHeap<Comparable>::makeNewBinomialNode(BinomialNode<Comparable>* t)
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr&&t->right == nullptr)
		return new BinomialNode<Comparable>(t->theElement);
	else
		return new BinomialNode<Comparable>(t->theElement, makeNewBinomialNode(t->left), makeNewBinomialNode(t->right));
}
template<typename Comparable>
void BinomialHeap<Comparable>::makeEmpty()
{
	if (theCurrentSize != 0)
	{
		for (int i = theCurrentSize - 1; i != 0; i--)
		{
			if (theHeap[i] != nullptr);
			HeapDelete(theHeap[i]);
		}
		HeapDelete(theHeap[0]);
	}
	return;
}
template<typename Comparable>
void BinomialHeap<Comparable>::HeapDelete(BinomialNode<Comparable> * t)
{
	if (t->left == nullptr&&t->right == nullptr)
	{
		delete t;
		t = nullptr;
		return;
	}
	else
	{
		if (t->left != nullptr)
			HeapDelete(t->left);
		if (t->right != nullptr)
			HeapDelete(t->right);
		return;
	}
}
template<typename Comparable>
const Comparable & BinomialHeap<Comparable>::findMin()const
{
	Comparable *temp = theHeap[0];
	for (i = 1; i != capacity(); i++)
	{
		if (*temp > theHeap[i])
			temp = theHeap[i];
	}
	return *temp;
}
template<typename Comparable>
void BinomialHeap<Comparable>::insert(const Comparable & item)
{
	if (!(currentSize % 2))//theHeap第一位是否有空位
	{
		theHeap[0] = new BinomialNode<Comparable>(item);
		currentSize++;
	}
	else
	{
		theHeap[0]->left = new BinomialNode<Comparable>(item);
		carry();
		currentSize++;
	}
	return;
}
template<typename Comparable>
void BinomialHeap<Comparable>::carry()
{
	;
	
}
