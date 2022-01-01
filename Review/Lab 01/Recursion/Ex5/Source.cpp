#include<iostream>
using namespace std;
int Count_digits(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n < 10)
	{
		return 1;
	}
	else {
		return 1 + Count_digits(n / 10);
	}
}
int Count_even_digits(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n < 10)
	{
		if (n % 2 == 0)
		{
			return 1;
		}
		else return 0;
	}
	else
	{
		if (n % 10 % 2 == 0)
		{
			return 1 + Count_even_digits(n / 10);
		}
		else return 0 + Count_even_digits(n / 10);
	}
}
int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	if (Count_digits(n) == Count_even_digits(n))
	{
		cout << "Moi so hang cua n deu la so chan" << endl;
	}
	else
	{
		cout << "Moi so hang cua n khong la so chan" << endl;
	}
}