#include <stdio.h>
#include "fibonacci.h"

int main()
{
    int n;
    scanf("%d",&n);
    mpz_t fibo;
    mpz_init(fibo);
    fib(n, &fibo);
    mpz_out_str(stdout, 10, fibo);
    printf("\n");
}
