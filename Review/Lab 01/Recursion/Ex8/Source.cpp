#include<iostream>
using namespace std;
int ReverseValue(int n,int sum)
{
	if (n == 0) return sum;
	if (n > 0)
	{
		sum = (sum * 10) + (n % 10);
		return ReverseValue(n / 10,sum);	
	}
}
int main()
{
	int n,sum=0;
	cout << "Moi nhap n: ";
	cin >> n;
	cout << ReverseValue(n,sum);
}