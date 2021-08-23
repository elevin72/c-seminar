#include "MatrixTranspose.h"

#define SIZE 2
int main(void)
{
    int matrix[SIZE][SIZE] = {{1,2},{-3,1}};
    /* int count = 0; */
    /* for (int i = 0; i < SIZE; ++i) */
    /* { */
    /*     for (int j = 0; j < SIZE; ++j) */
    /*     { */
    /*         matrix[i][j] = count++; */
    /*     } */
    /* } */
    PrintMatrix((int*)matrix, SIZE);
    printf("\n");
    int s = Transpose(matrix, SIZE);
    PrintMatrix((int*)matrix, SIZE);
    printf("%d\n", s);
}
