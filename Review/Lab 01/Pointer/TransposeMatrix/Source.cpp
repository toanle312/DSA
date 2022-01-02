#include<iostream>
using namespace std;
int** TransposeMatrix(int** a, int length, int width)
{
	int** a_t;
	a_t = new int* [length];
	for (int i = 0; i < length; i++)
	{
		a_t[i] = new int[width];
		for (int j = 0; j < width; j++)
		{
			a_t[i][j] = a[j][i];
		}
	}
	return a_t;
}
int main()
{
	int** a;
	a = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = i * j + 1;
		}
	}
	int** a_t = TransposeMatrix(a, 5, 4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		delete a[i];
	}
	delete[]a;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a_t[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++) {
		delete[]a_t[i];
	}
	delete[]a_t;
	return 0;
}