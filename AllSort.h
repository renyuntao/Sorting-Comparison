#ifndef ALLSORT_H
#define ALLSORT_H

// Bubble Sort
void BubbleSort(int arr[],int length);

// Quick Sort
void quicksort(int arr[],int low,int high);

// Quick Sort Variation
void quicksort_variation(int arr[],int low,int high);

// Insert Sort
void insertsort(int arr[],int length);

// Shell Sort
void shellsort(int arr[],int length);

// Select Sort
void selectsort(int arr[],int length);

// Heap Sort
void heapsort(int arr[],int length);

// Merge Sort
void mergesort(int arr[],int length);

// Radix Sort
void radixsort(int arr[],int length,int d,int m);
#endif
