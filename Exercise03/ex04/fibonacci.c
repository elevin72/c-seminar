#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

#include "fibonacci.h"

static mpz_t *fibNumbers;
static size_t saved = 0;

void Fibonacci(size_t n, mpz_t *ret)
{
    if (saved == 0)
    {
        printf("Calculating from scratch\n");
        FibonacciStart(n, ret);
    }
    if (n < saved)
    {
        printf("Fetching\n");
        mpz_set(*ret, fibNumbers[n]);
    }
    else // n >= saved
    {
        printf("Calculating based on previous results\n");
        FibonacciContinue(n, ret);
    }
}

void FibonacciStart(size_t n, mpz_t *ret)
{
    if (n >= 2)
    {
        if (!(fibNumbers = malloc((n + 1) * sizeof(mpz_t))))
        {
            printf("Uhoh\n");
        }
        saved = n + 1;
    }
    else // n == 0 || n == 1
    {
        if (!(fibNumbers = malloc(2 * sizeof(mpz_t))))
        {
            printf("Uhoh\n");
        }
        saved = 2;
    }
    mpz_init_set_ui(fibNumbers[0], 0);
    mpz_init_set_ui(fibNumbers[1], 1);
    if (n >= 2)
    {
        int first = 0;
        int second = 1;
        for (size_t index = 2; index <= n; ++index)
        {
            mpz_init(fibNumbers[index]);
            mpz_add(fibNumbers[index], fibNumbers[first], fibNumbers[second]);
            ++first;
            ++second;
        }
    }
    mpz_set(*ret, fibNumbers[n]);
}

void FibonacciContinue(size_t n, mpz_t *ret)
{
    if(!(fibNumbers = realloc(fibNumbers, (n + 1) * sizeof(mpz_t))))
    {
        printf("Uhoh\n");
    }
    int first = saved - 2;
    int second = saved - 1;
    for (size_t index = saved; index <= n; ++index)
    {
        mpz_init(fibNumbers[index]);
        mpz_add(fibNumbers[index], fibNumbers[first], fibNumbers[second]);
        ++first;
        ++second;
    }
    saved = n + 1;
    mpz_set(*ret, fibNumbers[n]);
}


void FibonacciFinish()
{
    for (int i = 0; i < saved; ++i)
    {
        mpz_clear(fibNumbers[i]);
    }
    free(fibNumbers);
    fibNumbers = NULL;
    saved = 0;
}
