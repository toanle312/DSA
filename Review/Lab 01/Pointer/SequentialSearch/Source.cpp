#include<iostream>
using namespace std;
int SequentialSearch(int* a, int n, int key)
{
	a[n] = key;
	int i = 0;
	while(a[i]!=key)
	{
		i++;
	}
	if (i == n)
	{
		return -1;
	}
	else return i;
}
int main()
{
	int* a = new int[5]{ -1,4,0,2,19 };
	int key = 2;
	// Vị trí của key trong mảng
	cout << SequentialSearch(a, 5, key);
}