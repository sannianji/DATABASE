#include "AVLTree.h"
template <typename Element>
AVLTree<Element>::AVLTree() : root(nullptr) {}
template <typename Element>
AVLTree<Element>::AVLTree(const AVLTree &rhs) { *this = rhs; }
template <typename Element>
AVLTree<Element>::~AVLTree() { clear(); }
template <typename Element>
const Element &AVLTree<Element>::findMin() const
{
	if (root != nullptr)
		return findMin(root)->elements;
	else
		return;
}
template <typename Element>
const AVLNode<Element> *AVLTree<Element>::findMin(const AVLNode<Element> *x) const
{
	if (x == nullptr)
		return x;
	if (x->LeftNode == nullptr)
		return x;
	else
		return findMin(x->LeftNode);
}
template <typename Element>
const Element &AVLTree<Element>::findMax() const
{
	if (root != nullptr)
		return findMax(root)->elements;
	else
		return;
}
template<typename Element>
const AVLNode<Element>* AVLTree<Element>::findMax(const AVLNode<Element>*x)const
{
	if (x == nullptr)
		return x;
	if (x->RightNode == nullptr)
		return x;
	else
		return findMin(x->RightNode);
}
template<typename Element>
std::ostream & AVLTree<Element>::
print(std::ostream & os)const
{
	os << print(os, root);
	return os;
}
template<typename Element>
std::ostream & AVLTree<Element>::
print(std::ostream & os, const AVLNode<Element>& x) const
{
	if (x == nullptr)
		return os;
	else
	{
		os << x->Elements;
		print(os, x->LeftNode);
		print(os, x->RightNode);
	}
}
template<typename Element>
bool AVLTree<Element>::contains(const Element& x)const
{
	return contains(x, root);
}
template<typename Element>
bool AVLTree<Element>::contains(const Element &x, const AVLNode<Element>* ptr)const
{
	if (ptr == nullptr)
		return false;
	else
	{
		if (x == ptr->Elements)
			return true;
		else
			((x > ptr->Elements) ? contains(x, ptr->RightNode) : contains(x, ptr->LeftNode);
	}
}
template<typename Element>
void AVLTree<Element>::clear()
{
	clear(AVLNode<Element>* & root);
}
template<typename Element>
void AVLTree<Element>::clear(AVLNode<Element> * & x)
{
	if (x == nullptr)
		return;
	else if (x->LeftNode == nullptr&&x->RightNode == nullptr)
	{
		delete x;
		x = nullptr;
		return;
	}
	else
	{
		clear(x->LeftNode);
		clear(x->RightNode);
		return;
	}
}
template<typename Element>
bool AVLTree<Element>::insert(const Element &x)
{
	return instert(x, root);
}
template<typename Element>
bool AVLTree<Element>::insert(const Element& x, const AVLNode<Element>* & ptr)
{
	if (ptr == nullptr)
	{
		ptr = new AVLNode<Element>(x);
	}
	else if (x < ptr->elements)
	{
		insert(x, ptr->right);
		if (heightReturn(ptr->LeftNode) - heightRturn(ptr->RightNode) == 2)
			RotateWithTheLeftChild(ptr);
		else
			DoubleRotateWithTheLeftChild(ptr);
	}
	else if (x > ptr->Elements)
	{
		insert(x, ptr->left);
		if (heightRturn(ptr->RightNode) - heightReturn(ptr->left) == 2)
			RotateWithTheRightChild(ptr);
		else
			DoubleRotateWithTheRightChild(ptr);
	}
	else
		;
	ptr->height = max(heightRturn(ptr->LeftNode), heightRturn(ptr->RightNode)) + 1;
}

int max(int lhs, int rhs)
{
	return lhs > rhs ? lhs : rhs;
}

template<typename Element>
void RotateWithTheLeftChild(AVLNode<Element>* & ptr)
{
	AVLNode<Element>* ptr_lef = ptr->LeftNode;
	ptr->LeftNode = ptr_lef->RightNode;
	ptr_lef->RightNode = ptr;
	ptr->height = max(heightRturn(ptr->LeftNode), heightRturn(ptr->RightNode)) + 1;
	ptr_left->height = max(heightReturn(ptr_lef->LeftNode), heightReturn(ptr->height)) + 1;
	ptr = ptr_lef;
}
template<typename Element>
void RotateWithTheRightChild(AVLNode<Element>* & ptr)
{
	AVLNode<Element>* ptr_rht = ptr->RightNode;
	ptr->RightNode = ptr_rht->LeftNode;
	ptr_rht->LeftNode = ptr;
	ptr->height = max(heightReturn(ptr->leftNode), heightReturn(ptr->RightNode)) + 1;
	ptr_rht->height = max(heightReturn(ptr_rht->RightNode), ptr->height) + 1;
	ptr = ptr_rht;
}
template<typename Element>
void DoubleRotateWitheTheLeftChild(AVLNode<Element>* &ptr)
{
	RotateWithTheLeftChild(ptr->LeftNode);
	RotateWithTheRightChild(ptr);
}
template<typename Element>
void DoubleRotateWitheTheRightChild(AVLNode<Element>* & ptr)
{
	RotateWithTheRightChild(ptr->RightNode);
	RotateWithTheLeftChild(ptr);
	
}
