#include<iostream>
using namespace std;
void SwapComlums(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		swap(a[i][1], a[i][3]);
	}
}
void SwapRows(int** a, int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		swap(a[1][j], a[2][j]);
	}
}
int main()
{
	int** a;
	a = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = i * j + 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//Hoán đổi cột 2 và 4
	SwapComlums(a, 3, 4);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	// Hoán đổi dòng 2 và 3
	SwapRows(a, 3, 4);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}