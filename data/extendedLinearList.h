#pragma once
#ifndef __EXTENDEDLINEARLIST_H
#define __EXTENDEDLINEARLIST_H
#include "linearList.h"
template<typename T>
class extendedLinearList :public linearList<T>
{
public:
	virtual ~extendednLinearList() {}
	virtual void clear() = 0;
	virtual void push_back(const T& theElement) = 0;
};
template<typename T>
void extendednChian<T>::clear()
{
	while
}
#endif