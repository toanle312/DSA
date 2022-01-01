#include<iostream>
using namespace std;
int Pow(int x,int n)
{
	if (n == 1)
	{
		return x;
	}
	return x * Pow(x,n - 1);
}
int main()
{
	int n;
	int x;
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Ket qua "<<x<<"^"<<n<<" la : " << Pow(x,n);
}