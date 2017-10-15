#pragma once
#ifndef __TREE_H
#define __TREE_H
#include <iostream>
template<typename T>
struct binaryTreeNode
{
	T element;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;

	binaryTreeNode():leftChild(nullptr),rigthChild(nullptr){}
	binaryTreeNode(const T& theElement) :element(theElement), leftChild(nullptr), rightChild(nullptr) {}
	binaryTreeNode(const T& theElement, binaryTreeNode<T>* theLeftChild, binaryTreeNode<T>* theRightChild)
		:element(theElement), leftChild(theLeftChild), rightChild(theRightChild) {}
};
template<typename T>
void visit(binaryTreeNode<T>* t)
{
	std::cout << t->element <<" ";
}
template<typename T>
void preOrder(binaryTreeNode<T> *t)
{
	if (t != nullptr)
	{
		visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}
template<typename T>
void inOrder(binaryTreeNode<T> *t)
{
	if (t != nullptr)
	{
		inOrder(t->leftChild);
		visit(t);
		inOrder(t->rightChild);
	}
}
template<typename T>
void postOrder(binaryTreeNode<T> *t)
{
	if (t != nullptr)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		visit(t);
	}
}
template<typename T>
void infix(binaryTreeNode<T>* t)
{
	if (t != nullptr)
	{
		cout << "(";
		infix(t->leftChild);
		cout << t->element;
		infix(t->rightChild);
		cout << ")";
	}
}
template<typename T>
class binaryTree
{
public:
	virtual ~binaryTree() {}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual void preOrder(void(*) (T *)) = 0;
	virtual void inOrder(void(*)(T*)) = 0;
	virtual void postOrder(void(*)(T*)) = 0;
	virtual void levelOrder(void(*)(T*)) = 0;
};
template<typename E>
class linkedBinaryTree :public binaryTree<binaryTreeNode<E>>
{
public:
	linkedBinaryTree() { root = nullptr; treeSize = 0; }
	~linkedBinaryTree() { erase(); }
	bool empty() { return treeSize==0; }
	int size() { return treeSize; }
	void preOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit;
		postOrder(root);
	}
	void postOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit;
		postOrder(root);
	}
	void inOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit;
		inOrder(root);
	}
	//void levelOrder(void(*)(binaryTreeNode<E>*));
	void erase()
	{
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}
	int height()const { return height(root); }
private:
	binaryTreeNode<E> *root;
	int treeSize;

	static int height(binaryTreeNode<E>* t);
	static void(*visit)(binaryTreeNode<E>*);
	static void preOrder(binaryTreeNode<E>*t);
	static void inOrder(binaryTreeNode<E>* t);
	static void postOrder(binaryTreeNode<E>* t);
	static void dispose(binaryTreeNode<E> *t) { delete t; }
};
template<typename E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{
	if (t != NULL)
	{
		linkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}
template<typename E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t)
{
	if (t != NULL)
	{
		inOrder(t->leftChild);
		linkedBinaryTree<E>::visit(t);
		inOrder(t->rightChild);
	}
}
template<typename E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E>*t)
{
	if (t != NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		linkedBinaryTree<E>::visit();
	}
}
template<typename E>
int linkedBinaryTree<E>::height(bianryTreeNode<E> *t)
{
	if (t == NULL)
		return 0;
	int hl = height(t->leftChild);
	int hr = height(t->rigthChild);
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}
struct booster
{
	int degradeToLeaf;
	int degradeFromParent;
	bool boosterHere;

	void output(std::ostream& out)const
	{
		out << boosterHere << " " << degradeToLeaf << " " << degradeFromParent << " ";
	}
};
std::ostream& operator<<(std::ostream &out, booster x)
{
	x.output(out); return out;
}
int tolerance;
void placeBooster(binaryTreeNode<booster> *x)
{
	x->element.degradeToLeaf = 0;
	binaryTreeNode<booster>* y = x->leftChild;
	if (y != NULL)
	{
		int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
		if (degradation > tolerance)
		{
			x->element.boosterHere = true;
			x->element.degradeToLeaf = y->element.degradeFromParent;
		}
		else
			x->element.degradeToLeaf = degradation;
	}
	y = x->rightChild;
	if (y != NULL)
	{
		int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
		if (degradation > tolerance)
		{
			y->element.boosterHere = true;
			degradation = y->element.degradeFromParent;
		}
		if (x->element.degradeToLeaf < degradation)
			x->element.degradeToLeaf = degradation;
	}
}
#endif