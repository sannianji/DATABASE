#pragma once
#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H
#include<vector>
template<typename Comparable>
struct BinomialNode
{
	Comparable theElement;
	BinomialNode * left;
	BinomialNode * right;

	BinomialNode(Comparable el, BinomialNode * lt = nullptr, BinomialNode * rt = nullptr)
		:theElement(el), left(lt), right(rt) {}


};
template<typename Comparable>
bool BinomialNode<Comparable>::operator>(BinomialNode<Comparable> & lhs, BinomialNode<Comparable> & rhs)
{
	return lhs.theElement>rhs.theElement;
}
template<typename Comparable>
class BinomialHeap
{
public:
	BinomialHeap() :currentSize(0), theHeap(0, nullptr) {};
	BinomialHeap(const BinomialHeap & rhs);
	BinomialHeap & operator=(const BinomialHeap &);
	~BinomialHeap() { makeEmpty(); }

	bool isEmpty()const { return capacity() == 0; }
	int capacity()const { return currentSize; }
	const Comparable findMin()const;

	void insert(const Comparable & item);
	void makeEmpty();//not complete

private://data
	std::vector<BinomialNode<Comparable>*> theHeap;
	int currentSize;//根据currentSize，确定是否需要合并

privare://functions
	BinomialNode<Comparable>* makeNewBinomialNode(BinomialNode<Comparable> *);
	BinomialQueue<Comparable>& clone();
	void HeapDelete(BinomialNode<Comparable>);
	void carry();
};
#endif
