#include <stdio.h>

/**
 * Swaps to ints
 */
void swap(int *a, int *b);

/**
 * In place finds the transpose of a square matrix
 *
 * @param matrix The matrix to be transposed. It should be of type int**
 * @param n
 *
 * @return 0 if not symmtetric, 1 if skew-symmetric, 2 if symmetric
 */
int Transpose(int (*matrix)[], size_t n);

/**
 * Prints a matrix of size n, with some decent formatting
 *
 * @param matrix The matrix to be printed. It should be of type int**
 * @param n
 */
void PrintMatrix(int *matrix, size_t n);

