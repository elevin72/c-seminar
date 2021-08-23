#include <math.h>
#include <gmp.h>


void fib(int n, mpz_t *ret)
{
    mpz_t first;
    mpz_t second;
    mpz_init_set_ui(first, 0);
    mpz_init_set_ui(second, 1);
    if (n == 0)
    {
        mpz_set_ui(*ret, 0);
        return;
    }
    if (n == 1)
    {
        mpz_set_ui(*ret, 1);
        return;
    }
    for (size_t index = 0; index < n-1; ++index)
    {
        mpz_add(*ret, first, second);
        mpz_set(first, second);
        mpz_set(second, *ret);
    }
}


