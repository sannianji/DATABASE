#pragma once
#ifndef __TEST_H
#define __TEST_H
template<class T>
T rSum(T a[],int n)
{
	if (n > 0)
		return rSum(a, n - 1) + a[n- 1];
	return 0;
}
template <typename T>
T the_cout(T a)
{
	return a;
}

template<class T>
void permutations(T list[], int k, int m)
{
	if (k == m)
	{
		copy(list, list + m + 1, std::ostream_iteraor<T>(cout, ""));
		cout << endl;
	}
	else
		for (int i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			permutations(list, k + 1, m);
			swap(list[k], list[i]);
		}
}
#endif