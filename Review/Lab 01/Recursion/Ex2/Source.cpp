#include<iostream>
using namespace std;
int Giaithua(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * Giaithua(n - 1);
}
int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Tich tu 1 den n la: " << Giaithua(n);
}