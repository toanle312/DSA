#include<iostream>
using namespace std;
// Lưu ý: BinarySearch chỉ được sử dụng khi mảng đã được sắp xếp
int BinarySearch(int* a, int n, int key)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == key)
		{
			return mid;// Đã tìm thấy key trong mảng
		}
		if (a[mid] < key)
		{
			l = mid + 1;// Duyệt từ mid đến cuối
		}
		else
		{
			r = mid - 1;// Duyệt từ dầu đến mid
		}
	}
	return -1;
}
int main()
{
	int* a = new int[6] { -5,-1,0,3,4,6 };
	int key=-1;

	// Vị trí của key trong mảng
	cout << BinarySearch(a, 6, key);
}