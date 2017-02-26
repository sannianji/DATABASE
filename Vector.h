#ifndef VECTOR_H
#define VECTOR_H
#define SPARE_CAPSCITY 50
template<typename Object>
class Vector 
{
public:
	explicit Vector(int inttheSize = 0)
		: theSize(inttheSize), theCapacity(inttheSize + SPARE_CAPSCITY)
	{
		object = new Object[theCapacity];
	}
	Vector(const Vector& rhs) :objects(NULL) { operator=(rhs); }
	~Vector() { delete[] object; }
	const Vector& operator=(Vector& rhs) {
		if (this != &rhs) {
			delete[] object;
			theSize = rhs.theSize;
			theCapacity = rhs.theCapacity;
			
			obeject = new Object(theCapacity);
			for (auto k = 0; k != theSize; k++)
				object[k] = rhs.object[k];
		}
		return *this;
	}
	void reserve(const int newCapacity)
	{
		if (newCapacity < theSize)
			return;//防止数据丢失
		Object *oldobject = object;
		object = new Object(newCapacity);
		for (int k = 0; k != theSize; k++)
			object[k] = oldobject[k];
		delete[] oldobject;
		theCapacity = newCapacity;
	}
	void resize(const int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize);
		theSize = newSize;
	}
	Object& operator[](int index)
	{
		return object[index];
	}
	bool empty()
	{
		return size();
	}
	int size() const
	{
		return theSize;
	}
	int capacity() const
	{
		return theCapacity;
	}
	void push_back(Object& obj)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		object[theSize++] = obj;
	}
	void pop_back()
	{
		theSize--;
	}
	const Object& back() const
	{
		return object[size() - 1];
	}
	typedef Object* iterator;
	typedef const Object* const_iterator;
	iterator begin()
	{
		return &object[0];
	}
	iterator end() {
		return &objec[size()];
	}
	const_iterator cbegin() const
	{
		return &object[0];
	}
	const_iterator cend() const { return &object[size()]; }
private:
	int theSize;
	int theCapacity;
	Object* object;
};
#endif
