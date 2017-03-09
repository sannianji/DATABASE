#pragma once
#ifndef LIST_H
#define LIST_H
template<typename Object>
struct Node
{
public:
	Object data;
	Node* next;
	Node* prev;
	Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr)
		:data(d), prev(p), next(n) {}
};
template<class Object>
class List
{
private:
	struct Node;
public:
	class const_iterator
	{
	public:
		const_iterator() : current(nullptr) {}
		const Object& operator*()const
		{
			return retrieve();
		}
		const_iterator &operator++()
		{
			current = curren->next;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		bool operator==(const const_iterator& rhs)const
		{
			return current == rhs.current;		
		}
		bool operator!=(const const_iterator& rhs)const
		{
			return !(*this == rhs);
		}
	protected:
		Node* current;
		const List<Object> *thisList;
		Object& retrieve() const { return current->data; }
		const_iterator(const List<Object>& lst,Node* p) :theList(&lst),current(p) {}
		friend class List<Object>;
		void assertIsValid() const
		{
			if (theList == nullptr || current == nullptr || current == theList->head)
				throw IteratorOutofBoundsException();
		}
	};
	class iterator :public const_iterator
	{
	public:
		iterator() {}
		Object& operator*()
		{
			return retrieve();
		}
		const Object & operator*( ) const 
		{
			return const_iterator::operator*();
		}
		iterator& operator++()
		{
			current = current->next; 
			return*this;
		}
		iterator &operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	protected:
		iterator(Node* p) :const_iterator(p) {}
		friend class List<Object>;
	};
public:
	List() { init(); }
	List(const List& rhs)
	{
		init();
		*this = rhs;
	}
	~List()
	{
		clear();
		delete head;
		delete tail;
	}
	const List& operator=(const List &rhs)
	{
		if (this == &rhs)
			return *this;
		clear();
		for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
			push_back(*itr);
		return *this;
	}
	iterator begin() { return iterator(head->next); }
	const_iterator begin()const { const_iterator itr(*this, head); return ++itr; }
	iterator end() { return iterator(tail); }
	const_iterator end()const { return iterator(tail); }
	int size() const { return theSize; }
	bool empty() const { return size() == 0; }
	void clear() { while (size() != 0) pop_front; }
	Object& front() { return *begin(); }
	Object& back() { return *--end(); }
	const Object& front() const { return *begin(); }
	const Object& back() const { return*--end(); }
	void push_back(const Object&X) { insert(end(), X); }
	void pop_front() { erase(begin()); }
	void pop_back() { earase(--end()); }
	iterator insert(iterator itr, const Object& X)//缺乏检查iterator
	{
		itr.assertIsValid();
		Node* p = itr.current;
		theSize++;
		return iterator(p->prev = prev->next = new Node(X, p->preve, p));
	}
	iterator erase(iterator itr)//缺乏类型检查
	{
		Node *p = itr.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;
		return reVal;
	}
	iterator erase(iterator start, iterator end)
	{
		for (iterator itr = start; itr != end;)
			itr = erase(itr);
		return end;
	}
private:
	Node* head;
	Node* tail;
	int theSize;
	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
}; 
#endif
