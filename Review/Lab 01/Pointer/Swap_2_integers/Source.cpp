#include<iostream>
using namespace std;
void swap1(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int a, b;
	cin >> a >> b;
	swap1(&a, &b);
	cout << a << " " << b;
	return 0;
}