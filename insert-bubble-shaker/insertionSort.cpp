#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
void insertionSort(int a[], int n)
{
     for (int i = 1; i < n; i++)
     {
          int key = a[i];
          int j = i - 1;
          while (j >= 0 && key < a[j])
          {
               a[j + 1] = a[j];
               j--;
          }
          a[j + 1] = key;
     }
     for (int i = 0; i < n; i++)
     {
          cout << a[i] << " ";
     }
}
void insertion_sort_experiment(int a[], int n, int &count_cmp)
{
     for (int i = 1; ++count_cmp && i < n; i++)
     {
          int key = a[i];
          int j = i - 1;
          while ((++count_cmp && j >= 0) && (++count_cmp && key < a[j]))
          {
               a[j + 1] = a[j];
               j--;
          }
          a[j + 1] = key;
     }
     for (int i = 0; ++count_cmp && i < n; i++)
     {
          cout << a[i] << " ";
     }
}
int main()
{
     int a[8] = {6, 5, 3, 1, 8, 7, 2, 4};
     //insertion_sort(a, 8);
     int cmp = 0;
     auto start = high_resolution_clock::now();
     insertionSort(a, 8);
     auto stop = high_resolution_clock::now();
     auto runtime = stop - start;
     cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << endl;

     system("pause");
     return 0;
}