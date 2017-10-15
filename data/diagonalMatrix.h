#pragma once
#ifndef __DIAGONALMATRIX_H
#define __DIAGONALMATRIX_H
#include "dbhead.h"
template<typename T>
class diagonalMatrix
{
public:
	diagonalMatrix(int theN = 10);
	~digonalMatrix() { delete[] element; }
	T get(int, int)const;
	void set(int, int, const T&);
private:
	int n;
	T* element;
};
template<typename T>
diagonalMatrix<T>::diagonalMatrix(int theN)
{
	if (theN < 1)
		throw illegalParameterValue("Matrix size must be > 0");
	n = theN;
	element = new T[n];
}
template<typename T>
T diagonalMatrix<T>::get(int i, int j)const
{
	if (i<1 || i>n || j<1 || j>n)
		throw matrixIndexOutOfBounds();
	if (i == j)
		return element[i - 1];
	else
		return 0;
}
template<typename T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue)
{
	if (i < 1 || j < 1 || i>n || j>n)
		throw matrixIndexOutOfBounds();
	if (i == j)
		element[i - 1] = newValue;
	else
		if (newValue != 0)
			throw illegalParameterValue("nondiagonal elements must be zero ");
}
#endif