// Sinan Bilkay
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
//#include<fstream>
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
using namespace std;
using std::chrono::nanoseconds;

int main()
{
    ofstream fileout;
	fileout.open("result.txt");
    std::random_device rd;
    std::mt19937 gen(rd());
    int step =100;
    cout << "length\tmerge\tmergesorted\tquick\tquick sorted\theap\theapsorted" << endl;
    fileout <<"length\tmerge\tmergesorted\tquick\tquick sorted\theap\theapsorted" << endl;
    for (int len = step; len<=10000;len+=step){
        nanoseconds mer(0);
        nanoseconds quick(0);
        nanoseconds heap(0);
        nanoseconds mer_sorted(0);
        nanoseconds quick_sorted(0);
        nanoseconds heap_sorted(0);
        int* arr = new int [len];
        int* copy_array = new int[len];
        int* sorted_array= new int[len];
        for (int i = 0 ; i < len; i++){
            arr[i] = i;
        }
        std::shuffle(arr, arr + len, gen);
        mer = mergeTime(arr, copy_array, len);
        quick += quickSortTime(arr, copy_array, len);
        heap += heapSortTime(arr, copy_array, len);
        quick_sorted += quickSortTime(copy_array,sorted_array,  len);
        mer_sorted += mergeTime(copy_array,sorted_array,  len);
        heap_sorted += heapSortTime(copy_array,sorted_array, len);
        cout << len << "\t" << mer.count()/100 << "\t" << mer_sorted.count()/100 <<"\t\t" <<
        quick.count()/100 <<"\t" <<quick_sorted.count()/100 << "\t\t" << heap.count()/100 << "\t"
        << heap_sorted.count()/100 <<endl;
        fileout << len << "\t" << mer.count()/100 << "\t" << mer_sorted.count()/100 <<"\t\t" <<
        quick.count()/100 <<"\t" <<quick_sorted.count()/100 << "\t\t" << heap.count()/100 << "\t"
        << heap_sorted.count()/100 <<endl;

        delete [] arr;
        delete [] copy_array;
        delete [] sorted_array;

    }

    fileout.close();


    return 0;
}
