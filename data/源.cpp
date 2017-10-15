#include<iostream>
using namespace std;
static int i = 0;
class M
{
public:
	M() {}
	~M() { cout << i << endl; i++; }
};
int main()
{
	M* theArray = new M[10];
	delete[] theArray;
	system("pause");
}