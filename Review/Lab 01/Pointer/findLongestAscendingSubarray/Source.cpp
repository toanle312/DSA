#include<iostream>
using namespace std;
int* findLongestAscendingSubarray(int* a, int n, int& length)
{
	// Quy hoạch động
	// Gọi f[i] là độ dài dãy con tăng dài nhất tại vị trí i
	int f[100];
	int res = 1;

	// Bước cơ sở của QHĐ
	// Nếu mảng có một phần tử thì độ dài dãy con tăng là 1
	f[0] = 1;

	// Biến lưu vị trí
	int pos = 0;

	for (int i = 1; i < n; i++)
	{
		// Xem như chưa tìm được độ dài dãy con tăng ở vị trí i
		f[i] = 0;
		for (int j = 0; j < i; j++)
		{
			// Nếu tốn tại phần tử nhỏ hơn a[i]
			if (a[j] < a[i])
			{
				/* 
				   Độ dài dãy con tăng dài nhất tại vị trí i sẽ bằng
				   độ dài dãy con tăng lớn nhất trong đoạn từ 0 -> i-1 cộng thêm cho 1
				   (tính luôn phần tử a[i] nên mới cộng thêm 1) 
				*/
				f[i] = max(f[i], f[j] + 1);
			}
		}
		// Tìm độ dài dãy con tăng dài nhất
		res = max(f[i], res);
		/* 
		   Lưu vị trí mà tại đó độ dài dãy con tăng là dài nhất
		   nghĩa là lưu lại vi trí i mà f[i] lớn nhất 
		*/
		pos = i;
	}
	int k = 0;
	int* a1 = new int[res];
	length = res;
	while (pos >= 0)
	{
		/* 
		   lưu lại từng giá trị của dãy con tăng
		   Lưu từng phần tử tại các vị trí có độ dài dãy con tăng nhỏ hơn res
		   Hay lưu từng phần tử tại vị trí i sao cho f[i] <= res
		*/
		if (f[pos] == res)
		{
			a1[k++] = a[pos];
			res--;
		}
		pos--;
	}
	return a1;
}
int main() {
	int* a = new int[10]{1,2,3,-1,4,5,6,7,0,11};
	
	int length = 0;
	int* a1=findLongestAscendingSubarray(a, 10, length);
	
	for (int i = 0; i < length; i++)
	{
		cout << a1[length-i-1] << " ";
	}

	delete[]a;
	delete[]a1;
	return 0;
}