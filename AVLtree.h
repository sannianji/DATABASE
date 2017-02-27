#ifndef AVL_TREE_H
#define AVL_TREE_H
template<typename Element>
struct AVLNode
{
	//class functions
	AVLNode(const Element & el,AVLNode* lf=nullptr,AVLNode* rt=nullptr,int ht=0)
	:LeftNode(lf),RightNode(rt),hight(0),Element(el){}

	//data
	AVLNode* LeftNode;
	AVLNode* RightNode;
	int hight;
	Element Elements;
	
	//interface functions
	int hightreturn(AVLNode* t)
		{return (t==nullptr)?-1:t->hight;}		
};
template<typename Element>
class AVLTree
{
public:
	//class functions
	AVLTree();
	AVLTree(const AVLTree &);
	~AVLTree();

	//interface functions for information
	const Element& findMin()const;
	const Element& findMax()const;
	const int hightMax()const;
	std::ostream& print()const;
	bool contains(const Element & )const;

	//interface functions can change the class
	bool insert(const Element & );
	bool remove(const Element & );
	void clear();	
	
private:
	//data
	AVLNode<Element>* Root;
	int AVLTreehight;
};
#endif