
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
