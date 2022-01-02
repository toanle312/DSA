#include<iostream>
using namespace std;
void inputArray(int*& a, int& n)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu a[" << i << "]: ";
		cin >> a[i];
	}
}
void outputArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	int* a = new int;
	int n;
	inputArray(a, n);
	outputArray(a, n);
	delete[]a;
	return 0;
}