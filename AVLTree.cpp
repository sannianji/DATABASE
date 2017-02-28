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
	if(x==nullptr)
		return x;
	if(x->RightNode==nullptr)
		return x;
	else 
		return findMin(x->RightNode);
}
template<typename Element>
std::ostream & AVLTree<Element>::
print(std::ostream & os)const
{
	os<<print(os, root);
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


