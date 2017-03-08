#include"BinaryHeap.h"
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable & x)
{
	if (currentSize == arry.size() - 1)
		arry.resize(currentSize * 2);

	int hole = ++currenSize;
	for (; hole > 1 && x < arry(hole / 2); hole / 2)
		arry[hole] = arry[hole / 2];
	arry[hole] = x;
}
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
	if (isEmpty())
		throw UnderflowException();
	arry[1] = arry[currentSize--];
	percolateDown(1);
}
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem)
{
	if (isEmpty())
		throw UnderflowException();
	minItem = arry[1];
	percolateDown(1);
}
template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
	int child;
	Comparable tem = arry[hole];

	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize&&arry[child + 1] < arry[child])
			child++;
		if (arry[child] < tmp)
			arry[hole] = arry[child];
		else
			break;
	}
	arry[hole] = tmp;
}
template<typename Comparable>
explicit BinaryHeap<Comparable>::BinaryHeap(const std::vector<Comparable> & item)
	:arry(item.size() + 10), currentSize(item.size())
{
	for (int i = 0; i < item.size(); ++i)
		arry[i + 1] = item[i];
	buildHeap();
}
template<typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--)
		percolateDown(i);
}
