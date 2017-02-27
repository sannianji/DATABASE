#pragma once
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
//重点利用递归解决问题，注意模板的使用过程中对于typename的添加，切记
//节点
template<typename Comparable>
struct BinaryNode
{
	Comparable element;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(const Comparable & theElement, BinaryNode* lt = nullptr, BinaryNode* rt = nullptr)
		:element(theElement), left(lt), right(rt) {}
};
template<typename Comparable>
class BinarySearchTree
{
public:
	//三大函数
	BinarySearchTree():root(nullptr){}
	BinarySearchTree(const BinarySearchTree&rhs) { *this = rhs; }
	~BinarySearchTree();
public:
	//接口只读函数
	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable & x)const;
	bool isEmpty()const;
	void printTree()const;
	//接口读写函数
	void makeEmpty();
	void insert(const Comparable & x);
	void remove(const Comparable & x);
public:
	//重载操作符
	const BinarySearchTree & operator=(const BinarySearchTree & rhs);

private:
	//数据
	BinaryNode<Comparable>* root;
private:
	//重点实现函数
	void insert(const Comparable & x, BinaryNode<Comparable> * & t);
	void remove(const Comparable & x, BinaryNode<Comparable> * & t);
	BinaryNode<Comparable> * findMin(BinaryNode<Comparable> * t)const;
	BinaryNode<Comparable> * findMax(BinaryNode<Comparable> * t)const;
	bool contains(const Comparable & x, BinaryNode<Comparable> * t)const;
	void makeEmpty(BinaryNode<Comparable> * & t);
	void printTree(BinaryNode<Comparable> * t) const;
	BinaryNode<Comparable> * clone(BinaryNode<Comparable> * t);
};
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
	else if (x<t->element)
		return contains(x, t->left);
	else if (x>t->element)
		return contains(x, t->right);
	else
		return true;
}
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * & t)
{
	if (t == nullptr)
		t = new BinaryNode<Comparable>(x, nullptr, nullptr);
	if (x>t->element)
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
#endif
