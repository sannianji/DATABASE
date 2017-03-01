#pragma once
#ifndef HASH_H
#define HASH_H
#include<string>
#include<vector>
#include<list>
#include<algorithm>
template<typename HashedObj>
class HashTable
{
public:
	explicit HashTable(int size = 101);

	bool contains(const HashedObj& x)const;

	void makeEmpty();
	void insert(const HashedObj&);
	void remove(const HashedObj&);

private:
	std::vector<HashedObj> theLists;
	int CurrentSize;

	void rehash();
	int myhash(const HashedObj& x)const;
};
int hash(const std::string &key);
int hash(int key);
template<typename HashedObj>
int HashTable<HashedObj>::myhash(const HashedObj & x)const
{
	int hashVal = hash(x);
	hashVal %= theLists.size();
	if (hashVal < 0)
		hashVal += theList.size();

	return hashVal;
}
class Employee
{
public:
	const std::string & getName() const
	{
		return name;
	}
	bool operator==(const Employee & rhs) const
	{
		return this->getName() == rhs.getName();
	}
	bool operator!=(const Employee & rhs)const
	{
		return !(this->getName() == rhs.getName());
	}
private:
	std::string name;
	double salary;
	int seniority;
};
template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	for (int i = 0; i < theLists.size(); i++)
		theLists[i].clear();
}
template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj&)const
{
	const std::list<HashedObj>& whichList = theLists[myhash(x)];
	return find(whichList.begin(), whichList.end(), x) != whichList.end();
}
template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj & x)
{
	std::list<HashedObj>& whichList = theLists[myhash(x)];
	std::list<HashedObj>::iterator itr = find(whichList.begin(), whichList.end(), x);
	if (itr == whichList.end())
		return false;

	whichList.erase(itr);
	--currentSize();
	return true;
}
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj & x)
{
	std::list<HashedObj>&whichList = theLists[myhash(x)];
	if (find(whichList.begin(), whichList.end(), x) != whichList.end())
		return false;
	whichList.push_back(x);
	if (++currenSize > theLists.size())
		rehash();
	return true;
}
template<typename HashedObj>
void HashTable<HashedObj>::rehash()
{
	std::vector<std::list<HashedObj>> oldLists = theLists;
	theLists.resize(nexPrime(2 * theLists.size()));
	for (int j = 0; j < theLists.size(); j++)
		theLists[j].clear();
	currentSize = 0;
	for (int i = 0; i < oldLists.size(); i++)
	{
		list<HashedObj>::_HAS_ITERATOR_DEBUGGING itr = oldLists[i].begin();
		while (itr != oldLists[i].end())
			insert(*iter++);
	}
}

#endif
