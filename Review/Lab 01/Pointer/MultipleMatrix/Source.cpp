#include<iostream>
using namespace std;
bool MultipleMatrix(int** a, int** b, int lengtha, int widtha, int lengthb, int widthb)
{
	int** c;
	if (lengtha == widthb || lengtha == lengthb && widtha == widthb)
	{
		c = new int* [widtha];
		for (int i = 0; i < widtha; i++)
		{
			c[i] = new int[lengthb];
			for (int k = 0; k < lengthb; k++)
			{
				c[i][k] = 0;
				for (int j = 0; j < lengtha; j++)
				{
					c[i][k] += a[i][j] * b[j][k];
				}
			}
		}
		for (int i = 0; i < widtha; i++)
		{
			for (int j = 0; j < lengthb; j++)
			{
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	else
	{
		c = new int* [widthb];
		for (int i = 0; i < widthb; i++)
		{
			c[i] = new int[lengtha];
			for (int k = 0; k < lengtha; k++)
			{
				c[i][k] = 0;
				for (int j = 0; j < lengthb; j++)
				{
					c[i][k] += a[i][j] * b[j][k];
				}
			}
		}
		for (int i = 0; i < widthb; i++)
		{
			for (int j = 0; j < lengtha; j++)
			{
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	return false;
}
int main()
{
	int** a;
	int** b;
	a = new int* [4];
	b = new int* [6];
	for (int i = 0; i < 4; i++)
	{
		a[i] = new int[6];
		for (int j = 0; j < 6; j++)
		{
			a[i][j] = i * j + 1;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		b[i] = new int[7];
		for (int j = 0; j < 7; j++)
		{
			b[i][j] = i * j + 1;
		}
	}
	//bằng 1 thì nhân được, bằng 0 thì không nhân được
	bool k=MultipleMatrix(a, b, 6, 4, 7, 6);
	cout << endl;
	cout <<"Result is: " << k << endl;
	return 0;
}