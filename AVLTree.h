#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
template <typename Element>
struct AVLNode
{
    //class functions
    AVLNode(const Element &el, AVLNode *lf = nullptr, AVLNode *rt = nullptr, int ht = 0)
	: LeftNode(lf), RightNode(rt), height(0), Element(el) {}

    //data
    AVLNode *LeftNode;
    AVLNode *RightNode;
    int height;
    Element Elements;

    //interface functions
    
};
template<typename Element>
int heightReturn(AVLNode<Element> *t)
{
	return (t == nullptr) ? -1 : t->height;
}
template <typename Element>
class AVLTree
{
  public:

    //class functions
    AVLTree();
    AVLTree(const AVLTree &);
    ~AVLTree();

    //interface functions for information
    const Element &findMin() const;
    const Element &findMax() const;
    const int heightMax() const { return (heightReturn(root) == -1) ? 0 : (heightReturn(root)); };
    std::ostream &print(std::ostream&) const;
    bool contains(const Element &) const;

    //interface functions can change the class
    bool insert(const Element &);
    bool remove(const Element &);
    void clear();

  private:
    //data
    AVLNode<Element> *root;

    int AVLTreeheight;
    //function
    const AVLNode<Element> *findMin(const AVLNode<Element> *) const;
    const AVLNode<Element> *findMax(const AVLNode<Element> *) const;
    bool contains(const Element &, const AVLNode<Element> *) const;
	std::ostream& print(std::ostream&, const AVLNode<Element>&)const;
    bool insert(const Element &, const AVLNode<Element> *&);
    bool remove(const Element &, const AVLNode<Element> *&);
    void clear(AVLNode<Element> *&);
};
#endif
