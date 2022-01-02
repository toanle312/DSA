#include<iostream>
using namespace std;
int Count_UocChung(int a, int b, int i)
{
	if (i > min(a, b))
	{
		return 0;
	}
	else return (a % i == 0 && b % i == 0) + Count_UocChung(a, b, i + 1);
}
int main()
{
	int a, b;
	cout << "Nhap vao hai so a va b: ";
	cin >> a >> b;
	cout << Count_UocChung(a, b, 1);
	cout << endl;
}