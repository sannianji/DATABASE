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
    if (x->left == nullptr)
        return x;
    else
        return findMin(x->left);
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
	if(x->right==nullptr)
		return x;
	else 
		return findMin(x->right);
}

