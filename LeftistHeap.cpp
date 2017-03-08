#include"LeftistHeap.h"
template<typename Comparable>
void LeftistHeap<Comparable>::merge(LeftistHeap & rhs)
{
	if (this == &rhs)
		return;
	root = merge(root, rhs.root);
}
template<typename Comparable>
LeftistNode<Comparable> * LeftistHeap<Comparable>::merge
(LeftistNode<Comparable> *h1, LeftistNode<Comparable> *h2)
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
LeftistNode<Comparable> * LeftistHeap<Comparable>::merge1
(LeftistNode<Comparable> * h1,LeftistNode<Comparable> * h2)
{
	if (h1->left = nullptr)
		h1->left = h2;
	else
	{
		h1->right = merge(h1->right, h2);
		if (h1->left->npl < h1->right - npl)
			swapChildren(h1);
		h1->npl = h1->right->npl + 1;
	}
	return h1;
}
template<typename Comparable>
void LeftistHeap<Comparable>::insert(const Comparable & x)
{
	root = merge(new LeftistNode<Comparable>(x), root);
}
template<typename Comparable>
void LeftistHeap<Comparable>::deleteMin()
{
	if (isEmpty())
		throw UnderflowException();
	LeftistNode<Comparable> * oldRoot = root;
	root = merge(root->left, root->right);
	delete oldRoot;
}
template<typename Comparable>
void LeftistHeap<Comparable>::deleteMin(Comparable & minItem)
{
	minItem = findMin();
	deletMin();
}
template<typename Comparable>
LeftistHeap<Comparable>::LeftistHeap():root(nullptr)
{}
template<typename Comparable>
LeftistHeap<Comparable>::~LeftistHeap()
{
	makeEmty();
}
template<typename Comparable>
void LeftistHeap<Comparable>::makeEmpty()
{
	if (root == nullptr)
		return;
	else
	{
		makeEmpty(root);
	}
	return;
}
template<typename Comparable>
void LeftistHeap<Comparable>::makeEmpty(LeftistNode<Comparable>* rhs)
{
	if (rhs->left != nullptr)
		makeEmpty(rhs->left);
	if (rhs->right != nullptr)
		makeEmpty(rhs->right);
	if (rhs->left == nullptr&&rhs->right == nullptr)
	{
		delete rhs;
		rhs = nullptr;
		return;
	}
}
template<typename Comparable>
LeftistHeap<Comparable>::LeftistHeap(const LeftistHeap<Comparable> & rhs)
{
	*this = rhs;
}
template<typename Comparable>
const LeftistHeap<Comparable>& LeftistHeap<Comparable>::operator=(const LeftistHeap<Comparable> & rhs)
{
	if (this == &rhs)
		return;
	else
	{
		this->makeEmpty();
		root = clone(rhs.root);
	}
}
template<typename Comparable>
bool LeftistHeap<Comparable>::isEmpty()const
{
	return root == nullptr;
}
template<typename Comparable>
const Comparable & LeftistHeap<Comparable>::findMin() const
{
	if(!isEmpty())
		return *root;
	else
		throw UnderflowException();
}
template<typename Comparable>
LeftistNode<Comparable> * LeftistHeap<Comparable>::clone(LeftistNode<Comparable> * rhs) const
{
	if (rhs == nullptr)
		return;
	else
		return new LeftistNode<Comparable>(rhs->element, clone(rhs->left), clone(t->right));
}
template<typename Comparable>
void LeftistHeap<Comparable>::swapChildren(LeftistNode<Comparable>* t)
{
	if (t == nullptr)
		return;
	else
	{
		LeftistNode<Comparable>* temp = t->left;
		t->left = t->right;
		t->right = temp;
		return;
	}
	
}

