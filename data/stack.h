#pragma once
#ifndef __STACK_H
#define __STACK_H
#include "arrayList.h"
#include "chain.h"
class stackEmpty
{
public:
	stackEmpty() :message("the stack is empty"){}
	stackEmpty(const char *c) :message(c) {}
	stackEmpty(const std::string &str) :message(str) {}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
template<typename T>
class stack
{
public:
	virtual ~stack() {}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& theElement) = 0;
};
template<typename T>
class derivedArrayStack :private arrayList<T>, public stack<T>
{
public:
	derivedArrayStack(int initialCapacity = 10) :arrayList<T>(initialCapacity) {}
	bool empty()const override { return arrayList<T>::empty(); }
	int size() const override{ return arrayList<T>::size(); }
	T& top()override
	{
		if (arrayList<T>::empty())
			throw stackEmpty();
		return arrayList<T>::get(arrayList<T>::size() - 1);
	}
	void pop()override
	{
		if (arrayList<T>::empty())
			throw stackEmpty();
		arrayList<T>::erase(arrayList<T>::size() - 1);
	}
	void push(const T& theElement)override
	{
		arrayList<T>::insert(arrayList<T>::size(), theElement);
	}
};
template<typename T>
class arrayStack :public stack<T>
{
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() override{ delete[] stack; }
	bool empty() const override { return stackTop == -1; }
	int size()const override { return stackTop + 1; }
	T& top()
	{
		if (stackTop == -1)
			throw stackEmpty();
		return stack[stackTop];
	}
	void pop()
	{
		if (stackTop == -1)
			throw stackEmpty();
		stack[stackTop--].~T();
	}
	void push(const T& theElement);
private:
	T* stack;
	int stackTop;//当前栈顶位置
	int arrayLength;//栈容量
};
template<typename T>
arrayStack<T>::arrayStack(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << "must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}
template<typename T>
void arrayStack<T>::push(const T& theElement)
{
	if (stackTop == arrayLength - 1) 
	{
		changeLength1D(stack, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	stack[++stackTop] = theElement;
}
template<typename T>
class linkedStack :public stack<T>
{
public:
	linkedStack(int initialCapacity = 10)
	{
		stackTop = NULL;
		stackSize = 0;
	}
	~linkedStack()override;
	bool empty()const override { return stackSize == 0; }
	int size()const override { return stackSize; }
	T& top() override {
		if (stackSize == 0)
			throw stackEmpty();
		return stackTop->element;
	}
	void pop()override;
	void push(const T& theElement)override
	{
		stackTop = new chainNode<T>(theElement, stackTop);
		stackSize++;
	}
private:
	chainNode<T>* stackTop;
	int stackSize;
};
template<typename T>
linkedStack<T>::~linkedStack()
{
	while (stackTop != NULL)
	{
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}
template<typename T>
void linkedStack<T>::pop()
{
	if (stackSize == 0)
		throw stackEmpty();
	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}
#endif