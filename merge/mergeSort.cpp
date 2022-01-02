#include "merge.h"

int merge(int *a, int left, int mid, int right)
{
    int *temp = new int[right - left + 1];

    int k = 0;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= right)
    {
        temp[k++] = a[j++];
    }

    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i - left];
    }
}

int mergeSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        return merge(a, left, mid, right);
    }
}
