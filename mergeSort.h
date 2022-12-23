#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
using namespace std;
using std::chrono::nanoseconds;

void merge(int* array, int left, int  mid, int right)
{
    int const leftSubArrSize = mid - left + 1;
    int const rightSubArrSize = right - mid;
    int *leftArray = new int[leftSubArrSize],
         *rightArray = new int[rightSubArrSize];
    for (int i = 0; i < leftSubArrSize; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < rightSubArrSize; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0,
        j = 0;
    int m = left;
    while (i < leftSubArrSize && j < rightSubArrSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[m] = leftArray[i];
            i++;
        }
        else {
            array[m] = rightArray[j];
            j++;
        }
        m++;
    }
    while (i < leftSubArrSize) {
        array[m] = leftArray[i];
        i++;
        m++;
    }

    while (j < rightSubArrSize) {
        array[m] = rightArray[j];
        j++;
        m++;
    }
}


void mergeSort(int* array, int p, int q)
{
    if (p >= q)
        return; // stopping the recursive when begin > end

    int mid = p + (q - p) / 2;
    mergeSort(array, p, mid);
    mergeSort(array, mid + 1, q);
    merge(array, p, mid, q);
}

nanoseconds mergeTime(int* arr, int* copy_array, int len) {
    std::copy(arr, arr + len, copy_array);
    auto begin = std::chrono::steady_clock::now();
    mergeSort(copy_array,0,len);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(copy_array, copy_array+len));
    nanoseconds total(end - begin);
    return total;
}


#endif //HEAPSORT_H
