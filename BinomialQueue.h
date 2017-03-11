#pragma once
#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H
#include<vector>
template<typename Comparable>
struct BinomialNode
{
	Comparable Element;
	BinomialNode * leftChild;
	BinomialNode * nextSibling;

	BinomialNode(const Comparable & theElement, BinomialNode *lt, BinomialNode *rt)
		:element(theElement), leftChild(lt), nextSibling(rt) {}
};
template<typename Comparable>
class BinomialQueue
{
public:
	BinomialQueue();
	BinomialQueue(const Comparable &);
	BinomialQueue(const BinomialQueue & rhs);
	~BinomialQueue();

	bool isEmpty()const;
	const Comparable & findMin() const;

	void insert(const Comparable & x);
	void deleteMin();
	void deleteMin(Comparable & minItem);

	void makeEmpty();
	void merge(BinomialQueue & rhs);

	const BinomialQueue & operator=(const BinomialQueue & rhs);

private:
	enum { DEFAULT_TREES = 1 };
	//data
	int currentSize;
	std::vector<BinomialNode<Comparable> *> theTrees;//所有二项队列的根节点的指针的集合
	//function
	int findMinIndex()const;
	int capacity() const;
	BinomialNode<Comparable>* combineTrees(BinomialNode<Comparable> * t1, BinomialNode<Comparable> * t2);
	void makeEmpty(BinomialNode<Comparable> * & t);
	BinomialNode<Comparable> * clone(BinomialNode<Comparable> * t)const;
};
#endif
