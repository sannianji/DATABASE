#include"stack.h"
void towersOfHanoi(int n, int x, int y, int z)
{
	if (n > 0)
	{
		towersOfHanoi(n - 1, x, z, y);
		std::cout << "move top disk of tower " << x << " to top of tower " << y << std::endl;
		std::cout << n << std::endl;
		new int[1024];
		towersOfHanoi(n - 1, z, y, x);
	}
}
arrayStack<int> tower[4];
void moveAndShow(int, int, int, int);
void towersOfHanoi(int n)
{
	for (int d = n; d > 0; d--)
		tower[1].push(d);
	moveAndShow(n, 1, 2, 3);
}
void showState();
int number = 0;
void moveAndShow(int n, int x, int y, int z)
{
	if (n > 0)
	{
		moveAndShow(n - 1, x, z, y);
		int d = tower[x].top();
		tower[x].pop();
		tower[y].push(d);
		showState();
		moveAndShow(n - 1, z, y, x);
	}
}
void showState()
{
	std::cout << "times: "<<++number << std::endl;
	for (int i = 1; i < 4; i++)
	{
		std::cout << "tower: "<<i << std::endl;
		while (!tower[i].empty())
		{
			std::cout << tower[i].top()<<"\t";
			tower[0].push(tower[i].top());
			tower[i].pop();
		}
		std::cout<<std::endl;
		while (!tower[0].empty())
		{
			tower[i].push(tower[0].top());
			tower[0].pop();
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
/*
int main()
{
	towersOfHanoi(30);
	system("pause");
}*/