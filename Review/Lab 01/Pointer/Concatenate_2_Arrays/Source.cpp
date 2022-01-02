#include<iostream>
using namespace std;
int* Concatenate2Arrays(int* a, int* b, int na, int nb)
{
	int* newArray = new int[na + nb];
	for (int i = 0; i < na + nb; i++)
	{
		if (i >= na)
		{
			newArray[i] = b[i - na];
		}
		else newArray[i] = a[i];
	}
	return newArray;
}
int main()
{
	int* a = new int[5]{ 1,2,3,4,5 };
	int* b = new int[3]{ 6,7,8 };
	int* ab = Concatenate2Arrays(a, b, 5, 3);
	for (int i = 0; i < 5+3; i++)
	{
		cout << ab[i] << " ";
	}
	delete[]ab;
	return 0;
}