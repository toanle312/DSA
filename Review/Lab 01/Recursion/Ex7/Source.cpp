#include<iostream>
using namespace std;
int UCLN(int a, int b)
{
	if (a > b)
	{
		if (b == 0) return a;
		return UCLN(b, a % b);
	}
	else
	{
		if (a == 0) return b;
		return UCLN(a, b % a);
	}
}
int main()
{
	int a, b;
	cout << "Nhap vao hai so a va b: ";
	cin >> a >> b;
	cout << UCLN(a, b) << endl;
	cout << (a * b) / UCLN(a,b);
}