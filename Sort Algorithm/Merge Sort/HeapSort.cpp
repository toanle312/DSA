#include<iostream>
using namespace std;
void SWAP(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void Heapify(int a[], int n, int i)
{
	int LargestNode = i;// Khởi tạo một cái parent
	int LeftNode = i * 2 + 1;// Left của parent
	int RightNode = i * 2 + 2;// Right của parent

	// So sánh parent với Left
	if (LeftNode<n && a[LeftNode]>a[LargestNode])
	{
		LargestNode = LeftNode;
	}
	
	// So sánh parent với Right
	if (RightNode<n && a[RightNode]>a[LargestNode])
	{
		LargestNode = RightNode;
	}

	// Cập nhật node lớn nhất nếu node lớn nhất không là parent ban đầu	
	if (LargestNode != i)
	{
		// Tiếp tục truy vết các node lớn nhất cho đến cuối Heap(đệ quy)
		SWAP(a[LargestNode], a[i]);
		// Recursion
		Heapify(a, n, LargestNode);
	}

}
void HeapSort(int a[], int n)
{
	// Xây dựng Max Heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(a, n, i);
	}

	// Trích xuất từng phần tử lớn nhất của Max Heap ứng với các gốc tương tứng
	for (int i = n - 1; i > 0; i--)
	{
		// Đưa gốc hiện tại đến mục cuối cùng của Heap
		SWAP(a[0], a[i]);
		// Loại bỏ phần tử cuối ra khỏi Heap và bắt đầu truy vết từ gốc (vị trí i = 0)
		Heapify(a, i, 0);
	}
}
int main()
{
	int a[9] = { 5,7,1,8,6,9,4,2,3 };
	HeapSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}