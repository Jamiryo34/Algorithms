#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#include <algorithm>
#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
using namespace std;
using std::chrono::nanoseconds;
void heapify(int* arr, int n, int i)
{
    int maximum = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[maximum])
        maximum = left;

    if (right < n && arr[right] > arr[maximum])
        maximum = right;


    if (maximum != i) {
        swap(arr[i], arr[maximum]);


        heapify(arr, n, maximum);
    }
}
cx

void heapSort(int* arr, int len)
{

    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);

    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
nanoseconds heapSortTime(int* arr, int* copy_array, int len) {
    std::copy(arr, arr + len, copy_array);
    auto begin = std::chrono::steady_clock::now();
    heapSort(copy_array,len);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(copy_array, copy_array+len));
    nanoseconds total(end - begin);
    return total;
}

#endif // HEAPSORT_H
