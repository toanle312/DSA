#include<iostream>
using namespace std;
int* findMax(int* a, int n) {
	int* max = &a[0];
	for (int i = 1; i < n; i++)
	{
		if (*max < a[i])
		{
			max = &a[i];
		}
	}
	return max;
}
int main() {
	int* a = new int[5]{-3,0,4,2,-6};
	cout<<*findMax(a, 5);
	delete[]a;
	return 0;
}