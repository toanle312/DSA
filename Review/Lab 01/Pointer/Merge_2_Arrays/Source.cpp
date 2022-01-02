#include<iostream>
using namespace std;
int* Merge2Arrays(int* a, int* b, int na, int nb)
{
	int* newArray = new int[na + nb];
	int i = 0, j = 0;
	int k = 0;
	// Trộn hai mảng theo đúng thứ tự
	while (i < na && j < nb)
	{
		if (a[i] <= b[j])
		{
			newArray[k++] = a[i++];
		}
		else
		{
			newArray[k++] = b[j++];
		}
	}
	// Nếu mảng a còn phần tử thì đưa hết vào mảng mới
	while (i < na)
	{
		newArray[k++] = a[i++];
	}
	// Nếu mảng b còn phần tử thì đưa hết vào mảng mới
	while (j < nb)
	{
		newArray[k++] = b[j++];
	}
	return newArray;
}
int main()
{
	int* a = new int[5]{ 1,5,9,12,14 };
	int* b = new int[3]{ 4,8,13 };
	int* ab = Merge2Arrays(a, b, 5, 3);
	for (int i = 0; i < 5 + 3; i++)
	{
		cout << ab[i] << " ";
	}
	delete[]ab;
	return 0;
}