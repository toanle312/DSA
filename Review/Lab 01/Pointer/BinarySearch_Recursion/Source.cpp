#include<iostream>
using namespace std;
// Lưu ý: BinarySearch chỉ được sử dụng khi mảng đã được sắp xếp
int BinarySearch(int* a, int key,int l,int r)
{
	if (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (a[mid] == key)
		{
			return mid;// Đã tìm thấy key trong mảng
		}

		if (a[mid] < key)
		{
			return BinarySearch(a,key,mid+1,r);// Duyệt từ mid đến cuối
		}
		else 
		{
			return BinarySearch(a,key,l,mid-1);// Duyệt từ dầu đến mid
		}
	}
	return -1;
}
int main()
{
	int* a = new int[7]{ -5,-1,0,1,3,4,6 };

	int n = 7;
	int key = 1;

	// Vị trí của key trong mảng
	cout << BinarySearch(a, key, 0, n - 1);

	return 0;
}