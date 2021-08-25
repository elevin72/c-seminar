#include <stdlib.h>

typedef struct Dog_t
{
    char *name;
    float weight;
} Dog;


typedef int (*Compare_d)(Dog*, Dog*);

void Swap(Dog *a, Dog *b);

int Partition(Dog dogs[], int lo, int hi, Compare_d LessThan);

void QuickSort(Dog dogs[], int lo, int hi, Compare_d LessThan);

void SortDogs(Dog *dogs, size_t size, Compare_d LessThan);

void PrintArray(Dog dogs[], size_t size);
