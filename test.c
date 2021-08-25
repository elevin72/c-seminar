

#include <stdio.h>
#include <gmp.h>

typedef struct 
{
    char a;
    int b;
    char c;
    int d;
    char e;
} A;

int main()
{
    A a = {0x11, 0x22222222, 0x33, 0x44444444, 0x55};
    /* int b = 0x22222222; */
    /* char c =0x33; */
    /* int d = 0x44444444; */
    /* char e =0x55; */
    printf("%c", a.a);
}
