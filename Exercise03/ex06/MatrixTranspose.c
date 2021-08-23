#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Transpose(int (*matrix)[], size_t n)
{
    int *matrix_p = (int*)matrix;
    int symmetric = 1;
    int skewSymmetric = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i < j)
            {
                int *a = matrix_p + (i*n) + j;
                int *b = matrix_p + (j*n) + i;
                if (*a != *b)
                {
                    symmetric = 0;
                }
                else if (abs(*a) != abs(*b))
                {
                    skewSymmetric = 0;
                    symmetric = 0;
                }
                else
                {
                    swap(matrix_p + (i*n) + j, matrix_p + (j*n) + i);
                }
            }
        }
    }
    return skewSymmetric + symmetric;
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

