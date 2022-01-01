#include<iostream>
using namespace std;
// Hàm trộn hai mảng 
void Merge(int a[], int l, int mid, int r)
{
	// Số phần tử mảng thứ nhất
	int n1 = mid - l + 1;

	// Số phần tử mảng thứ hai 
	int n2 = r - mid;

	// Tạo hai mảng tạm để lưu hai mảng con
	int* a1 = new int[n1];
	int* a2 = new int[n2];

	// Sao chép hai mảng con vào hai mảng tạm
	for (int i = 0; i < n1; i++)
	{
		a1[i] = a[l + i];
	}

	for (int i = 0; i < n2; i++)
	{
		a2[i] = a[mid + 1 + i];
	}


	int i = 0, j = 0;

	// k là vị trí hiện tại trong mảng a
	int k = l;

	// Trộn hai mảng theo đúng thứ tự
	while (i < n1 && j < n2)
	{
		if (a1[i] <= a2[j])
		{
			a[k++] = a1[i++];
		}
		else a[k++] = a2[j++];
	}

	// Nếu mảng thứ nhất còn phần tử thì copy vào mảng a
	while (i < n1)
	{
		a[k++] = a1[i++];
	}

	// Nếu mảng thứ hai còn phần tử thì copy vào mảng a
	while (j < n2)
	{
		a[k++] = a2[j++];
	}

	// Xóa bộ nhớ hai mảng tạm
	delete[]a1, a2;

}
// Hàm chia đôi mảng và gọi hàm trộn 
void _MergeSort(int a[], int l, int r)
{
	// Kiểm tra xe còn chia đôi mảng được hay không
	if (l < r)
	{
		// Tìm vị trí chính giữa của mảng
		int mid = l + (r - l) / 2;

		// Sắp xếp mảng thứ nhất từ vị trí l đến mid
		_MergeSort(a, l, mid);

		// Sắp xếp mảng thứ hai từ vị trí mid + 1 đến r
		_MergeSort(a, mid + 1, r);

		// Trộn hai mảng đã sắp xếp
		Merge(a, l, mid, r);
	}
}
// Hàm thực hiện sắp xếp trộn 
void MergeSort(int a[], int n)
{
	_MergeSort(a, 0, n - 1);
}
int main()
{
	int a[6] = {5,-1,7,9,0,1};
	MergeSort(a, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}