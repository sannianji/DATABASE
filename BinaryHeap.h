#pragma once
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include<vector>
template<typename Comparable>
class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100);
	explicit BinaryHeap(const std::vector<Comparable> & item);

	bool isEmpty() const;
	const Comparable & findMin() const;

	void insert(const Comparable & x);
	void deleteMin();
	void deleteMin(Comparable& minItem);
	void makeEmpty();
private:
	int currentSize;
	std::vector<Comparable> arry;
	void buildHeap();
	void percolateDown(int hole);
};
#endif
