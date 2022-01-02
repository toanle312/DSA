#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void bubbleSort_experiment(int a[], int n, int& count_cmp)
{
    for (int i = 0; ++count_cmp && i < n - 1; i++)
    {
        for (int j = 0; ++count_cmp && j < n - i - 1; j++)
        {
            if (++count_cmp && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int a[8] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    bubbleSort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}