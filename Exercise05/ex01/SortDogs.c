#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "SortDogs.h"

/**
 * Returns 1 if dog1.name < dog2.name
 * Returns 0 otherwise
 */
int CompareByName(Dog *dog1, Dog *dog2)
{
    return (strcmp(dog1->name, dog2->name) < 0) ? 1 : 0;
}

/**
 * Returns 1 if dog1.name < dog2.name
 * Returns 0 otherwise
 */
int CompareByWeight(Dog *dog1, Dog *dog2)
{
    return (dog1->weight < dog2->weight) ? 1 : 0;
}

void SortDogs(Dog *dogs, size_t size, Compare_d LessThan)
{
    QuickSort(dogs, 0 , size - 1, LessThan);
}

void QuickSort(Dog dogs[], int lo, int hi, Compare_d LessThan)
{
    if (lo < hi)
    {
        int p = Partition(dogs, lo, hi, LessThan);
        QuickSort(dogs, lo, p - 1, LessThan);
        QuickSort(dogs, p + 1, hi, LessThan);
    }
}

int Partition(Dog dogs[], int lo, int hi, Compare_d LessThan)
{
    Dog pivot = dogs[hi];
    int i = lo - 1;
    for (int j = lo; j <= hi - 1; ++j)
    {
        if (LessThan(&dogs[j], &pivot))
        {
           ++i;
           Swap(&dogs[i], &dogs[j]);
        }
    }
    Swap(&dogs[i+1], &dogs[hi]);
    return i+1;
}


void PrintArray(Dog dogs[], size_t size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
    {
        /* printf("%f", dogs[i]); */
        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void Swap(Dog *a, Dog *b)
{
    Dog temp = *a;
    *a = *b;
    *b = temp;
}

