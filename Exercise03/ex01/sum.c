#include "sum.h"

int sum(int *integers, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += integers[i];
    }
    return sum;
}

