#pragma once
#ifndef __DBHEAD_H
#define __DBHEAD_H
#include <string>
#include <iostream>
#include <sstream>
inline int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
class illegalParameterValue
{
public:
	illegalParameterValue() :message("Illegal parameter value") {}
	illegalParameterValue(char *theMessage) { message = theMessage; }
	illegalParameterValue(std::string& str) { message = str; }
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
inline int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}
template<typename Input, typename Output>
void copy(Input from, Input end, Output start)
{
	for (; from != end; from++, start++)
		*start = *from;
}
class illegalIndex
{

public:
	illegalIndex() :message("the index is illegal") {}
	illegalIndex(const char* theMessage) :message(theMessage) {}
	illegalIndex(const std::string str) :message(str) {}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}
template<typename T>
void changeLength2D(T*& a, int oldRow, int oldLine, int newRow, int newLine)
{
	if (newRow < 0 || newLine < 0)
		throw illegalParameterValue("new length must be>=0");
	T* temp = new T[newRow][newLine];
	int row = min(oldRow, newRow);
	int line = min(oldLine, newLine);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < line; j++)
			temp[i][j] = a[i][j];
	delete[] a;
	a = temp;
}
template<typename Input, typename Output>
void copy_backward(Input from, Input end, Output last)
{
	while (from != end)
		*(--last) = *(--end);
}
class matrixIndexOutOfBounds
{
public:
	matrixIndexOutOfBounds() :message("The index is out of bounds ") {}
	matrixIndexOutOfBounds(char * c) :message(c) {}
	matrixIndexOutOfBounds(std::string &str) : message(str) {}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
class matrixSizeMismatch
{
public:
	matrixSizeMismatch() :message("These two matrixs' size are not matched") {}
	matrixSizeMismatch(char * c) :message(c) {}
	matrixSizeMismatch(std::string str) :message(str) {}
	void outputMessage() { std::cout << message << std::endl; }
private:
	std::string message;
};
#endif