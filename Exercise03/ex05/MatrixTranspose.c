#include <limits.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Transpose(int (*matrix)[], size_t n)
{
    int *matrix_p = (int*)matrix;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i < j)
            {
                swap(matrix_p + (i*n) + j, matrix_p + (j*n) + i);
            }
        }
    }
}

void PrintMatrix(int (*matrix)[], size_t n)
{
    int *matrix_p = (int*)matrix;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(max < *(matrix_p + (i*n) + j))
            {
                max = *(matrix_p + (i*n) + j);
            }
            // The below line is terribly ugly, so I did the above 4 lines instead
            /* max = (max < *(matrix_p + (i*n) + j)) ? *(matrix_p + (i*n) + j) : max; */
        }
    }
    int maxDigits = 0;
    while (max != 0)
    {
        max = max / 10;
        ++maxDigits;
    }
    maxDigits += 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%*d", maxDigits, *(matrix_p + (i*n) + j));
        }
        printf("\n");
    }
}

