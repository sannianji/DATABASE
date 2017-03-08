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
	BinarySearchTree(const BinarySearchTree<Comparable> & rhs) { *this = rhs; }
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
#endif
