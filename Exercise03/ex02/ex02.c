#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "QuickSort.h"



int main()
{
    int size = 10;
    float array[size];
    srand(time(NULL));

    for (size_t i = 0; i < size; ++i)
    {
        array[i] = ((float)rand()/(float)(RAND_MAX)) * size;
    }

    PrintArray(array, size);
    Sort(array, sizeof(array)/ sizeof(float));
    PrintArray(array, size);
    return 0;
}
