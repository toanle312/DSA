#include<iostream>
using namespace std;
void SWAP(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectionSort(int a[], int n)
{
	int min = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;// xem a[min]=a[i] là phần tử nhỏ nhất
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])// Nếu a[j]<a[min] thì a[j] là nhỏ nhất
			{
				min = j;// Lưu lại vị trí a[min] vừa tìm được
			}
		}
		if (a[min] != a[i])// Nếu a[min] không phải là a[i] ban đầu thì đổi chỗ hai phần tử
		{
			SWAP(a[i], a[min]);
		}
	}
}
void OutputArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	int arr[5] = { 5,2,3,1,4 };
	SelectionSort(arr, 5);
	OutputArray(arr, 5);
}