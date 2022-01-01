#include<iostream>
#include<ctime>
using namespace std;
void generateMatrix1(int** &a, int& length, int& width)
{
	cin >> width;
	cin >> length;
	a = new int* [width];
	for (int i = 0; i < width; i++)
	{
		a[i] = new int[length];
		for (int j = 0; j < length; j++)
		{
			a[i][j] = rand() % (10 - (-10) + 1) - 10;
		}
	}
}
int main()
{
	int length, width;
	int** a;
	generateMatrix1(a, length, width);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}