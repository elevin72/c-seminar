#include "MatrixTranspose.h"

int main(void)
{
    int n = 4;
    int matrix[n][n];
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = count++;
        }
    }
    PrintMatrix((int*)matrix, n);
    printf("\n");
    Transpose(matrix, n);
    PrintMatrix((int*)matrix, n);
}
