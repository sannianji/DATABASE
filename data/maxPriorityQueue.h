#pragma once
#ifndef __MAXPRIORITYQUEUE_H
#define __MAXPRIORITYQUEUE_H
#include <string>
#include <iostream>
class queueEmpty
{
public:
	queueEmpty() :message("the heap is empty") {}
	queueEmpty(const char *c) :message(c) {}
	queueEmpty(const std::string str) :message(str) {}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
template<typename T>
class maxPriorityQueue
{
public:
	virtual ~maxPriorityQueue() {}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual const T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& theElement) = 0;
};
template<typename T>
class maxHeap :public maxPriorityQueue
{
public:
	maxHeap() :heap(NULL), arrayLength(10), heapSize(0) {}
	maxHeap(int theCapacity) :arrayLength(theCapacity), heapSize(0) { heap = new T[arrayLength]; }
	~maxHeap() 
	{
		delete[] heap;
	}
	bool empty() const override { return size == 0; }
	int size()const override { return size; }
	const T& top() { return *heap; }
	void push(const T& theElement);
	void pop();
	void initialize(T* theHeap, int theSize);
private:
	int arrayLength;
	T* heap;
	int heapSize;
};  
template<typename T>
void maxHeap<T>::push(const T& theElement)
{
	if (heapSize == arrayLength - 1)
	{
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength = 2 * arrayLength;
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < theElement)
	{
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = theElement;
}
template<typename T>
void maxHeap<T>::pop()
{
	if (heapSize == 0)
		throw queueEmpty();

	heap[1].~T();
	T lastElement = heap[heapSize--];
	int currentNode = 1;
	int child = 2;
	while (child <= heapSize)
	{
		if (child < heapSize&&heap[child] < heap[child + 1])
			child++;

		if (lastElement >= heap[child])
			break;
		heap[currentNode] = heap[child];
		currentNode = Child;
		child *= 2;
	}
	heap[currentNode] = lastElement;
}
template<typename T>
void maxHeap<T>::initialize(T* theHeap, int theSize)
{
	delete[] heap;
	heap = theHeap;
	heapSize = theSize;

	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];
		int child = 2 * root;
		while (child <= heapSize)
		{
			if (child < heapSize&&heap[child] < heap[child + 1])
				child++;
			if (rootElement >= heap[child])
				break;

			heap[child / 2] = heap[child];
			child * 2;
		}
		heap[child / 2] = rootElement;
	}
}
#endif