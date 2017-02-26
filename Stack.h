#ifndef STACK_H
#define STACK_H
#include<vector>
template<typename Object>
class Stack
{
public:
	Stack() {}
	Stack(std::vector<Object> sta):stack(sta) {}
	Stack(Stack& sta):stack(sta.stack){}
	~Stack() {  }
	Stack& operator=(const Stack &rhs) 
	{
		if (this != &rhs)
		{
			stack = rhs.stack;
		}
		return *this;
	}
	void pop() { stack.pop_back(); }
	void push(Object& ob) {stack.push_back(ob); }
	const Object& top() const{ return stack.back(); }
	int size() { return stack.size(); }
	bool isEmpty() { return stack.empty(); }
private:
	std::vector<Object> stack;
};
#endif
