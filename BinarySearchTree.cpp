#include"BinarySearchTree.h"
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x) const
{
	return contains(x, root);
}
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
	insert(x, root);
}
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
	remove(x, root);
}
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode<Comparable> * & t)
{
	if (t == nullptr)
		return;
	else if (x > t->element)
		remove(x, t->right)
	else if (x < t->element)
		remove(x, t->left)
	else if (t->left != nullptr&&t->right != nullptr)
	{
		t->element = find(t->right())->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode<Comparable> *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode<Comparable> * t)const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (x > t->element)
		return contains(x, t->right);
	else
		return true;
}
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * & t)
{
	if (t == nullptr)
		t = new BinaryNode<Comparable>(x, nullptr, nullptr);
	if (x > t->element)
		insert(x, t->right)
	else if (x <= t->element)
		insert(x, t->left)
	else
		;
}
template<typename Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> * t)const
{
	if (t == nullptr)
		return nullptr;
	else if (t->left == nullptr)
		return t;
	return findMin(t->left);
}
template<typename Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> * t)const
{
	if (t = nullptr)
		return nullptr;
	else if (t->right == nullptr)
		return t;
	return findMax(t->right);
}
template<typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin()const
{
	return findMin(root)->element;
}
template<typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax()const
{
	return findMax(root)->element;
}
template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode<Comparable> * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
	makeEmpty(root);
}
template<typename Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(const BinarySearchTree<Comparable> & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}
template<typename Comparable>
BinaryNode<Comparable> *BinarySearchTree<Comparable>::clone(BinaryNode<Comparable> * t)
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right));
}
template<typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
	return root == nullptr;
}
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(std::ostream & out)const
{
	if (root == nullptr)
		out << "Empty tree" << endl;
	printTree(root);
}
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode<Comparable> * t,std::ostream & out)const
{
	if (t != nullptr)
	{
		printTree(t->left, out);
		out << t->element << endl;
		printTree(t->right, out);
	}
}
