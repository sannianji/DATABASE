#pragma once
#ifndef __MATRIX_H
#define __MATRIX_H
#include <iostream>
#include "dbhead.h"

template<typename T>
class matrix
{
	friend std::ostream& operator<<(std::ostream&, const matrix<T>&);
public:
	matrix(int theRows = 0, int theColumns = 0);
	matrix(const matrix<T>&);
	~matrix() { delete[] elements; }
	int rows() const { return theColumns; }
	T& operator()(int i, int j)const;
	matrix<T>&operator=(const matrix<T>&);
	matrix<T> operator+()const;
	matrix<T> operator+(const matrix<T>&)const;
	matrix<T> operator- () const;
	matrix<T> operator- (const matrix<T>&)const;
	matrix<T> operator*(const matrix<T>&)const;
	matrix<T>& operator+=(const T&);
private:
	int theRows;//ÐÐ
	int theColumns;//ÁÐ
	T *element;
};
template<typename T>
matrix<T> matrix::operator+()const
{

}
template<typename T>
matrix<T>::matrix(int theRows, int theColumns)
{
	if (theRows < 0 || theColumns < 0)
		throw illegalParameterValue("Rows and columns must be >= 0");
	if ((theRows == 0 || theColumns = 0) && (theRows != 0 || theColumns != 0))
		throw illegalParameterValue("Either both or neither rows and columns should be zero");
	this->theRows = theRows;
	this->theColumns = theColumns;
	element = new T[theRows*theColumns];
}
template<typename T>
matrix<T>::matrix(const matrix<T>& m)
{
	theRows = m.theRows;
	theColumns = m.theColumns;
	element = new T[theRows*theColumns];

	copy(m.element, m.element + m.theColumns*m.theRows, element);

}
template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
	if (this != m)
	{
		delete[] element;
		theRows = m.theRows;
		theColumns = m.theColumns;
		copy(m.element, m.element + theColumns*theRows, element);
	}
	return *this;
}
template<typename T>
T& matrix<T>::operator()(int i, int j)const
{
	if (i<1 || i>theRows || j<1 || j>theColumns)
		throw matrixIndexOutOfBounds();
	return element[(i - 1)*theColumns + j - 1];
}
template<typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
	if ((theRows != m.theRows) || (theColumns != m.theColums))
		throw matrixSizeMismatch();

	matrix<T> w(theRows, theColumns);
	for (int i = 0; i < therows*theColumns; i++)
		w.element[i] = m.element[i] + this->element[i];

	return w;
}
template<typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& m)const
{
	if (theColumns != m.theRows)
		throw matrixSizeMismatch();

	matrix<T> w(theRows, m.theColumns);

	int ct = 0, cm = 0, cw = 0;
	for (int i = 1; i < theRows; i++)
	{
		for (int j = i; j <= m.theColumns; j++)
		{
			T sum = element[ct] * m.element[cm];
			for (int k = 2; k <= theColumns; k++)
			{
				ct++;
				cm += m.theColumns;
				sum += element[ct] * m.element[cm];
			}
			w.element[cw++] = sum;

			ct -= theColumns - 1;
			cm = j;
		}
		ct += theColumns;
		cm = 0;
	}
	return w;
}
#endif