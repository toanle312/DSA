#include<iostream>
using namespace std;
void SwapArrays(int*& a, int*& b, int& na, int& nb)
{
	if (na == nb)
	{
		for (int i = 0; i < na; i++)
		{
			int temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}
	}
	else
	{
		int na1 = na;
		int nb1 = nb;
		int* a1 = new int[na];
		int* b1 = new int[nb];
		for (int i = 0; i < na; i++)
		{
			a1[i] = a[i];
		}
		for (int i = 0; i < nb; i++)
		{
			b1[i] = b[i];
		}
		delete[]a;
		delete[]b;
		a = new int[nb];
		b = new int[na];
		for (int i = 0; i < nb; i++)
		{
			a[i] = b1[i];
		}
		for (int i = 0; i < na; i++)
		{
			b[i] = a1[i];
		}
		na = nb1;
		nb = na1;
	}
	
}
void Swap2Arrays(int*& a, int*& b, int& na, int& nb)
{
	int* c = a;
	a = b;
	b = c;
	swap(na, nb);
}
int main()
{
	int* a = new int[5]{ 1,2,3,4,5 };
	int* b = new int[8]{ 0,1,2,3,4,5,6,10 };
	int n = 5, m = 8;
	Swap2Arrays(a, b, n, m);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << " ";
	}
	delete[]a;
	delete[]b;
	return 0;
}