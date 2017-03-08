#pragma once
#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H
template<typename Comparable>
struct LeftistNode
{
	Comparable element;
	LeftistNode * left;
	LeftistNode * right;
	int npl;

	LeftNode(const Comparable & theElement, LeftistNode * lt = nullptr, LeftistNode* rt = nullptr, int np = 0)
		:element(theElement), left(lt), right(rt), npl(np) {}

};
template<typename Comparable>
class LeftistHeap
{
public:
	LeftistHeap();
	LeftistHeap(const LeftistHeap & rhs);
	~LeftistHeap();
	
	bool isEmpty()const;
	const Comparable & findMin() const;

	void insert(const Comparable & x);
	void deleteMin();
	void deleteMin(Comparable & minItem);
	void makeEmpty();
	void merge(LeftistHeap & rhs);

	const LeftistHeap &operator=(const LeftistHeap& rhs);
private:
	
	//data
	LeftistNode<Comparable> * root;

	LeftistNode<Comparable> * merge(LeftistNode<Comparable> * h1, LeftistNode<Comparable> * h2);
	LeftistNode<Comparable> * merge1(LeftistNode<Comparable> * h1, LeftistNode<Comparable> * h2);
	void * makeEmpty(LeftistNode<Comparable> * rhs);
	
	void swapChildren(LeftistNode<Comparable> * t);
	void reclaimMemory(LeftistNode<Comparable> * t);
	LeftistNode<Comparable> * clone(LeftistNode<Comparable> *)const;
};
#endif
