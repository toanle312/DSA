#include<iostream>
using namespace std;
// Hàm sắp xếp phân đoạn
void _QuickSort(int a[], int l, int r)
{
	// Nếu mảng có một phần tử thì không cần sắp xếp
	if (l >= r) return;

	// Tìm phần tử làm chốt (phần tử pivot)
	int mid = (l + r) / 2;
	int pivot = a[mid];

	// i là vị trí đầu đoạn, j là vị trí cuối đoạn
	int i = l, j = r;

	while (i < j)
	{
		// nếu phần tử bên trái nhỏ hơn pivot thì bỏ qua phần tử đó
		while (a[i] < pivot)
		{
			i++;
		}
		// nếu phần tử bên phái lớn hơn pivot thì bỏ qua phần tử đó
		while (a[j] > pivot)
		{
			j--;
		}

		// Sau khi kết thúc hai vòng while trên thì ta sẽ có
		// a[i] lớn hơn pivot và a[j] nhỏ hơn pivot
		if (i <= j)
		{
			// Nếu i khác j thì mới cần hoán đổi
			if (i < j) swap(a[i], a[j]);
			// Nếu i = j thì không cần hoán đổi
			i++;
			j--;	
		}
	}

	// Gọi đệ quy sắp xếp dãy bên trái pivot 
	_QuickSort(a, l, j);
	// Gọi đệ quy sắp xếp dãy bên phải pivot
	_QuickSort(a, i, r);
}
// Hàm sắp xếp chính 
void QuickSort(int a[], int n)
{
	_QuickSort(a, 0, n - 1);
}
int main()
{
	int a[7] = { 2,5,6,3,1,4,7 };
	QuickSort(a, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
}