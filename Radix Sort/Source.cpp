#include<iostream>
using namespace std;
void RadixSort(int a[], int n)
{
	int m;
	int* b = new int[n];
	m = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
		}
	}
	int exp = 1;
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			bucket[(a[i] / exp) % 10]++;
		}
		for (int i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1];
		}
		for (int i = n-1; i >= 0; i--)
		{	
			b[bucket[(a[i] / exp) % 10] - 1] = a[i];
			bucket[(a[i] / exp) % 10] --;
		}
		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}
		exp *= 10;
	}

}
int main()
{
	int a[6] = { 964,354,368,128,495,121 };
	RadixSort(a, 6);
	return 0;
}