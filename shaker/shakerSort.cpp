#include <iostream>
using namespace std;
void Swap(int &a, int &b)
{
     int temp = a;
     a = b;
     b = temp;
}
void shakerSort(int a[], int n)
{
     int left = 0;
     int right = n - 1;
     int mark = 0; // biến đánh dấu
     while (left < right)
     {
          // duyệt xuôi chiều
          for (int i = left; i < right; i++)
          {
               if (a[i] > a[i + 1])
               {
                    Swap(a[i], a[i + 1]);
                    mark = i; // đánh dấu lại vị trí cận trên
                    // đánh dấu lại vị trí mà từ vị trí đó -> n-1 thỏa tính tăng dần
               }
          }
          right = mark;
          // duyệt ngược chiều
          for (int i = right; i > left; i--)
          {
               if (a[i] < a[i - 1])
               {
                    Swap(a[i], a[i - 1]);
                    mark = i; // đánh dấu lại vị trí cận dưới
                    // đánh dấu lại vị trí mà từ vị trí đó -> 0 thỏa tính giảm dần
               }
          }
          left = mark;
     }
}

void shakerSort_experiment(int a[], int n, int &count_cmp)
{
     int left = 0;
     int right = n - 1;
     int mark = 0; // biến đánh dấu
     while (++count_cmp && left < right)
     {
          // duyệt xuôi chiều
          for (int i = left; ++count_cmp && i < right; i++)
          {
               if (++count_cmp && a[i] > a[i + 1])
               {
                    Swap(a[i], a[i + 1]);
                    mark = i; // đánh dấu lại vị trí cận trên
                    // đánh dấu lại vị trí mà từ vị trí đó -> n-1 thỏa tính tăng dần
               }
          }
          right = mark;
          // duyệt ngược chiều
          for (int i = right; ++count_cmp && i > left; i--)
          {
               if (++count_cmp && a[i] < a[i - 1])
               {
                    Swap(a[i], a[i - 1]);
                    mark = i; // đánh dấu lại vị trí cận dưới
                    // đánh dấu lại vị trí mà từ vị trí đó -> 0 thỏa tính giảm dần
               }
          }
          left = mark;
     }
}

int main()
{
     int a[8] = {8, 4, 9, 1, 5, 6, 7, 2};
     shakerSort(a, 8);
     for (int i = 0; i < 8; i++)
     {
          cout << a[i] << " ";
     }
     system("pause");
     return 0;
}