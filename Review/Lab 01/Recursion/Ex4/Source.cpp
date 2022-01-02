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
		return 1 + Count_digits(n/10);
	}
}
int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "So chu so cua n la: " << Count_digits(n);
}