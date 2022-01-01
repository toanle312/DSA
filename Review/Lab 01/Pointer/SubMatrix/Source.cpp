#include<iostream>
using namespace std;
int FindMaxValueOfSubMatrix(int** a, int m, int n, int ma, int na)
{
	int** SubMatrix = new int* [ma];
	for (int i = 0; i < ma; i++)
	{
		SubMatrix[i] = new int[na];
		for (int j = 0; j < na; j++)
		{
			SubMatrix[i][j] = 0;
		}
	}
	int max = -INT_MAX;
	for (int i = 0; i <= m - ma; i++)
	{
		for (int j = 0; j <= n - na; j++)
		{
			int s = 0;
			for (int i1 = i; i1 < i + ma; i1++)
			{
				for (int j1 = j; j1 < j + na; j1++)
				{
					s += a[i1][j1];
				}
			}
			if (s >= max)
			{
				max = s;
				int k = 0;
				for (int i1 = i; i1 < i + ma; i1++)
				{
					int l = 0;
					for (int j1 = j; j1 < j + na; j1++)
					{
						SubMatrix[k][l] = a[i1][j1];
						l++;
					}
					k++;
				}
			}
		}
	}
	for (int i = 0; i < ma; i++)
	{
		for (int j = 0; j < na; j++)
		{
			cout << SubMatrix[i][j]<<" ";
		}
		cout << endl;
	}
	return max;
}
int main()
{
	int arr[5][5]=
	{ 
		{1, 1, 1, 1, 1},
		{2, 2, 2, 2, 2},
		{3, 8, 6, 7, 3},
		{4, 4, 4, 4, 4},
		{5, 5, 5, 5, 5},
	};
	int** a = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = new int[5];
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = arr[i][j];
		}
	}
	cout << FindMaxValueOfSubMatrix(a, 5, 5, 3, 3);
	return 0;
}