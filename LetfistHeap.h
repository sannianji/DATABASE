#pragma once
#ifndef LEFTIST_HEAP_H
#define LEFTISR_HEAP_H
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
	void makeEmty();
	void merge(LeftistHeap & rhs);

	const LeftisHeap &operator=(const LeftisHeap& rhs);
private:
	struct LeftistNode
	{
		Comparable element;
		LeftistNode * left;
		LeftistNode * right;
		int npl;
		
		LeftNode(const Comparable & theElement, LeftistNode * lt = nullptr, LeftistNode* rt = nullptr, int np = 0)
			:element(theElement), left(lt), right(rt), npl(np) {}

	};
	LeftistNode * root;
	LeftistNode * merge(LeftistNode * h1, LeftistNode * h2);
	LeftistNode * mergel(LeftistNode * h1, LeftistNode * h2);

	void swapChildren(LeftistNode * t);
	void reclaimMemory(LeftistNode * t);
	LetfistNode * clone(LeftistNode * t)const;
};
template<typename Comparable>
void LeftistHeap<Comparable>::merge(LeftistHeap & rhs)
{
	if (this == &rhs)
		return;
	root = merge(root, rhs.root);
}
template<typename Comparable>
LeftistNode<Comparable> * LeftistHeap<Comparable>::merge(LeftistNode<Comparable> *h1, LeftistNode<Comparable> *h2)
{
	if (h1 == nullptr)
		return h2;
	if (h2 == nullptr)
		return h1;
	if (h1->element < h2->element)
		return merge1(h1, h2);
	else
		return merge1(h2, h1);
}
template<typename Comparable>
LeftistNode<Comparable> * LeftistHeap<Comparable>::merge1(LetistNode * h1, LeftistNode * h2)
{
	if (h1->left = nullptr)
		h1->left = h2;
	else
	{
		(h1->right = merge(h1->right, h2));
		if (h1->left->npl < h1->right - npl)
			swapChildren(h1);
		h1->npl = h1->right->npl + 1;
	}
	return h1;
}
#endif
