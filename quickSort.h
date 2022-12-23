#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int* arr, int p, int q)
{
    int pivot = arr[q];
    int i = (p - 1);

    for (int j = p; j <= q- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[q]);
    return (i + 1);
}

void quickSort(int* arr, int p, int q)
{
    if (p < q)
    {
        int pi = partition(arr, p, q);
        quickSort(arr, p, pi - 1);
        quickSort(arr, pi + 1, q);
    }
}
nanoseconds quickSortTime(int* arr, int* copy_array, int len) {
    std::copy(arr, arr + len, copy_array);
    auto begin = std::chrono::steady_clock::now();
    quickSort(copy_array,0,len);
    auto end = std::chrono::steady_clock::now();
    assert(std::is_sorted(copy_array, copy_array+len));
    nanoseconds total(end - begin);
    return total;
}
#endif // QUICKSORT_H_INCLUDED
