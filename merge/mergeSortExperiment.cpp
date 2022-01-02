#include "merge.h"

int merge(int *a, int left, int mid, int right, long long &count_compare)
{
    int *temp = new int[right - left + 1];

    int k = 0;
    int i = left;
    int j = mid + 1;

    while ((++count_compare && i <= mid) && (++count_compare && j <= right))
    {
        if (++count_compare && a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (++count_compare && i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (++count_compare && j <= right)
    {
        temp[k++] = a[j++];
    }

    for (int i = left; ++count_compare && i <= right; i++)
    {
        a[i] = temp[i - left];
    }
}

void mergeSort(int *a, int left, int right, long long &count_compare)
{
    if (++count_compare && left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(a, left, mid, count_compare);
    mergeSort(a, mid + 1, right, count_compare);
    merge(a, left, mid, right, count_compare);
}

double measureMerge(int* a,int n,long long &count_compare)
{
    auto start = high_resolution_clock::now();
    mergeSort(a, 0, n - 1,count_compare);
    auto stop = high_resolution_clock::now();
    auto runtime = stop - start;
    return duration<double, milli>(runtime).count();
}