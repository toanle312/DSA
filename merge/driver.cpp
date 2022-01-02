#include "merge.h"

int randomNumber(int n)
{
    return rand() % (n - 1 + 1) + 1;
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int *initRandomArray(int &n)
{
    cout << "How many elements?" << endl;
    cin >> n;
    cout << "Size of element?" << endl;
    int size;
    cin >> size;
    int *arr = new int[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = randomNumber(size);
    }
    return arr;
}

int main(int agrc, char **argv)
{
    int n;
    int *a = initRandomArray(n);
    long long count_compare = 0;
    cout << "-----------------------" << endl;
    cout << "Run Time: " << measureMerge(a, n,count_compare) << endl;
    cout << "Comparison: " << count_compare<<endl;
    system("pause");
    return 0;
}
