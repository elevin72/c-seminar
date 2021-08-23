#include <stdio.h>
#include "fibonacci.h"

int main()
{
    for (;;)
    {
        printf("Enter n: ");
        int n;
        scanf("%d",&n);
        mpz_t fibo;
        mpz_init(fibo);
        Fibonacci(n, &fibo);
        mpz_out_str(stdout, 10, fibo);
        mpz_clear(fibo);
        printf("\n");
    }
    FibonacciFinish();
    return 0;
}
