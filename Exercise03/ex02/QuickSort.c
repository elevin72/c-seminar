#include <stddef.h>
#include <math.h>
#include <stdio.h>

#include "QuickSort.h"

void Sort(float *array, size_t size)
{
    QuickSort(array, 0 , size - 1);
}

void QuickSort(float array[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = Partition(array, lo, hi);
        QuickSort(array, lo, p - 1);
        QuickSort(array, p + 1, hi);
    }
}

int Partition(float array[], int lo, int hi)
{
    float pivot = array[hi];
    int i = lo - 1;
    for (int j = lo; j <= hi - 1; ++j)
    {
        if (array[j] <= pivot)
        {
           ++i;
           Swap(&array[i], &array[j]);
        }
    }
    Swap(&array[i+1], &array[hi]);
    return i+1;
}

void Swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(float array[], size_t size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
    {
        printf("%f", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

