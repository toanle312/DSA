#include "heap.h"

void heapify(int *arr, int n, int i, long long &count_compare)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((++count_compare && l < n) && (++count_compare && arr[l] > arr[largest]))
        largest = l;

    if ((++count_compare && r < n) && (++count_compare && arr[r] > arr[largest]))
        largest = r;

    if (++count_compare && largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest, count_compare);
    }
}

void heapSort(int *arr, int n, long long &count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
    {
        heapify(arr, n, i, count_compare);
    }

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0, count_compare);
    }
}

double measureHeap(int *a, int n, long long &count_compare)
{
    auto start = high_resolution_clock::now();
    heapSort(a, n, count_compare);
    auto stop = high_resolution_clock::now();
    auto runtime = stop - start;
    return duration<double, milli>(runtime).count();
}
