#include <stdio.h>

int func(int a)
{
    return a-2;
}

int main()
{
    int a = 0;
    if (2 == func(4))
        a = 1;
    else
        a = 0;
    printf("%d", a);
    return 0;
}
