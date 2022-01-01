#include<iostream>
using namespace std;
int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int* a = new int[5]{ -1,4,0,2,19 };
	int key = 2;
	// Vị trí của key trong mảng
	cout << LinearSearch(a, 5, key);
}