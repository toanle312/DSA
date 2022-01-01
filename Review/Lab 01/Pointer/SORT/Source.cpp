#include<iostream>
using namespace std;
void SORT(int a[], int n)
{
	int* b = new int[n];
	int prev = INT_MIN;
	for (int j = 0; j < n; j++)
	{
		int i = 0;
		int min = INT_MAX;
		while (i < n)
		{
			if (a[i]<min && a[i]>prev)
			{
				min = a[i];
			}
			i++;
		}
		prev = min;
		b[j] = min;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
	delete[]b;
}
int main()
{
	int a[10] = { -1,3,9,0,-5,6,8,11,4,15 };
	SORT(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}