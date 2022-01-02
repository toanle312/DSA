#include<iostream>
#include<ctime>
using namespace std;
int** generateMatrix2(int* a, int* b, int na, int nb)
{
	int** newArray;
	newArray = new int* [na];
	for (int i = 0; i < na; i++)
	{
		newArray[i] = new int[nb];
		for (int j = 0; j < nb; j++)
		{
			newArray[i][j] = a[i] * b[j];
		}
	}
	return newArray;
}
int main()
{
	int* a = new int[3]{ 1,-5,0 };
	int* b = new int[5]{ 0,-1,2,-4,7 };
	int** ab = generateMatrix2(a, b, 3, 5);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << ab[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete[]ab[i];
	}
	delete ab;
}