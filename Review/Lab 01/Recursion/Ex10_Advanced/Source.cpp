#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Hàm hoán vị hai kí tự đầu của chuỗi
void swap_c(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

/*
	Hàm này được tham khảo từ đoạn code đầu tiên của trang web https ://www.it-swarm-vi.com/vi/c/tat-ca-cac-hoan-vi-cua-mot-chuoi-trong-c/1073212661/
	Đọc thêm từ nguồn của geeksforgeeks.org https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/
void Permute(char *a, int i, int n)
{
	// Nếu truy đến vị trí cuối cúng thì in ra chuỗi
	if (i == n - 1)
	{
		cout << a << endl;
	}
	else
	{
		/*
			> Bắt đầu thực hiện hoán vị
			> Hiển thị tất cả hoán vị với chữ cái ở vị trí i cố định
			> Hoán đổi chữ cái thứ i cho mỗi chữ cái còn lại
			> Ví dụ: ABCD, A cố định -> hoán vị BCD, rồi BCD lại tiếp tục giữ B cố định -> hoán vị CD
			> Tiếp tục như vậy đổi chỗ B với C,D sau khi hoàn thành các hoán vị trả về chuỗi ABCD ban đầu
			> Tiếp tục đổi chỗ A với B,C và D. Làm như v cho đến khi in ra đầy đủ các hoán vị
		*/
		for (int j = i; j < n; j++)
		{
			// Hoán vị hai phần tử thành công
			swap_c((a + i), (a + j));
			// Gọi đệ quy để hoán vị như cách hiểu ở trên
			Permute(a, i + 1, n);
			// Trả chuỗi về lại đúng với thứ tự trước khi hoán vị
			swap_c((a + i), (a + j));
		}
	}
}

int main()
{
	char s[100];
	strcpy(s, "ABCD");

	Permute(s, 0, strlen(s));

	return 0;
}