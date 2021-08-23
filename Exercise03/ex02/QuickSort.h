#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stddef.h>


void Swap(float *a, float *b);

int Partition(float array[], int lo, int hi);

void QuickSort(float array[], int lo, int hi);

void Sort(float *array, size_t size);

void PrintArray(float array[], size_t size);

#endif
