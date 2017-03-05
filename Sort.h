#pragma once
#ifndef SORT_H
#define SORT_H
#include<vector>
template<typename Comparable>
void insertionSort(std::vector<Comparable> & vec)
{
	for (int p = 1; p < vec.size(); p++)
	{
		int j;
		Comparable temp = vec[p];
		for (j = p; j != 0 && temp < vec[j - 1]; j--)
			vec[j] = vec[j - 1];
		vec[j] = temp;
	}
}
template<typename Comparable>
void insertionSort(std::vector<Comparable>::iterator & from, std::vector<Comparable>::iterator & to)
{
	auto b = a;
	for (auto a = from; a != to; ++a)
		Comparable item = &a;
	for (; b != from&&temp < *b; b--)
		*b = *(b - 1);
	*b = temp;
}
template<typename Iterator>
void insertionSort(const Iterator & begin, const Iterator & end)
{
	if (begin != end)
		insertionSortHelp(begin, end, *begin);
}
template<typename Iterator, typename Object>
void insertionSortHelp(const Iterator & begin, const Iterator & end, const Object & obj)
{
	instertionSort(begin, end, less<object>());
}
template<typename Iterator, typename Comparator>
void insertionSort(const Iterator & begin, const Iterator & end, Comparator lessThan)
{
	if (begin != end)
		insertionSort(begin, end, lessThan, *begin);
}
template<typename Iterator, typename Comparator, typename Object>
void insertionSort(const Iterator & begin, const Iterator & end, Comparator lessThan, const Object & obj)
{
	Iterator j;
	for (Iterator p = begin + 1; p != end; ++p)
	{
		Object temp = *p;
		for (j = p; j != begin&&lessThan(temp, *(j - 1)); --j)
			*j = *(j - 1);
		*j = temp;
	}
}
template<typename Comparable>
void shellsort(std::vector<Comparable> & vec)
{
	for (int gap = vec.size() / 2; gap > 0; gap / 2)
		for (int i = gap; i < vec.size(); i++)
		{
			Comparable temp = vec[i];
			int j = i;

			for (; j > gap&&temp < a[j - gap]; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
}

template<typename Comparable>
void heapsort(std::vector<Comparable> & vec)
{
	for (int i = vec.size() / 2; i >= 0; --i)
		percDown(vec, i, vec.size());
	for (int j = vec.size() - 1; j > 0; --j)
	{
		std::swap(vec[0], vec[j]);
		percDown(vec, 0, j);
	}
}

inline int  leftChild(int i)
{
	return 2 * i + 1;
}

template<typename Comparable>
void percDown(std::vector<Comparable> & vec, int i, int n)
{
	int child;
	Comparable temp;
	for (temp = vec[i]; leftchild(i) < n; i = child)
	{
		child = leftChild(i);
		if (child != n - 1 && vec[child] < vec[child + 1])
			child++;
		if (temp < vec[child])
			vec[i] = vec[child];
		else
			break;
	}
	vec[i] = temp;
}
template<typename Comparable>
void mergeSort(std::vector<Comparable> & vec)
{
	std::vector<Comparable> tempvec(vec.size());
	mergeSort(vec, tempvec, 0, vec.size() - 1);
}
template<typename Comparable>
void mergeSort(std::vector<Comparable> & vec, std::vector<Comparable> & tempvec, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(vec, tempvec, left, center);
		mergeSort(vec, tempvec, center + 1, right);
		merge(vec, tempvec, left, center + 1, right);
	}
}
template<typename Comparable>
void merge(std::vector<Comparable>& vec, std::vector<Comparable> & tempvec, int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tempPos = leftPos;
	int numElements = rightEnd - lefPos + 1;

	while (leftPose <= leftEnd&&rightPose <= rightEnd)
		if (vec[leftPos] <= vec[rightPos])
			tempvec[tempPos++] = vec[leftPos++];
		else
			tempvec[temPose++] = vec[rightPos++];
	while (leftPos < = leftEnd)
		tempvec[tempPos++] = vec[leftPos++];

	while (rightPose <= rightEnd)
		tempvec[tempPos++] = vec[rightPos++];
	
	for (int i = 0; i < numElements; i++, rightEnd--)
		vec[rightEnd] = tempvec[rightEnd];
}
template<typename Comparable>
void quicksort(std::vector < Comparable > & vec)
{
	quicksort(vec, 0, vec.size() - 1);
}
template<typename Comparable>
const Comparable & median3(std::vector<Comparable>&vec, int left, int right)
{
	int center = (left + right) / 2;
	if (vec[center] < vec[left])
		swap(vec[left], vec[center]);
	if (vec[right] < vec[left])
		swap(vec[left], vec[right]);
	if(vec[right]<vec[cenrer])
		swap(vec[center], vec[right]);

	swap(vec[center, vec[right - 1]]);
	return vec[right - 1];
}
template<typename Comparable>
void quicksort(std::vector<Comparable> & vec, int left, int right)
{
	if (left + 10 < right)
	{
		Comparable pivot = median3(vec, left, right);

		int i = left, j = right - 1;
		for (;;)
		{
			while (a[++i] < pivot) {}
			while (pivot < a[--j]) {}
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[i], a[right - 1]);

		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}
	else
		insertionSort(a, left, right);
}

#endif
