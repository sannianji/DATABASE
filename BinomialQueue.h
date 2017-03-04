#pragma once
#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H
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
	struct BinomialNode
	{
		Comparable Element;
		BinomialNode * leftChild;
		BinomialNode * nextSibling;

		BinomialNode(const Comparable & theElement, BinomialNode *lt, BinomialNode *rt)
			:element(theElement), leftChild(lt), nextSibling(rt) {}
	};

	enum { DEFAULT_TREES = 1 };

	int currentSize;
	vector<BinomialNode *> theTrees;

	int findMinIndex()const;
	int capacity() const;
	BinomialNode* combineTrees(BinomialNode * t1, BinomialNode * t2);
	void makeEmpty(BinomialNode * & t);
	BinomialNode * clone(BinomialNode * t)const;
};
#endif
