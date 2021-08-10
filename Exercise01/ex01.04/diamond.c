#include <string.h>
#include <stdio.h>

void PrintChar(char c, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%c", c);
}

void PrintLine(int i, int biggerHalf)
{
    PrintChar(' ', biggerHalf - (i/2));
    PrintChar('*', i);
    printf("\n");
}

int PrintDiamond(int x) 
{
    int retval;
    if (x % 2 == 0)
        retval = -1;
    int biggerHalf = (x / 2);
    for (int i = 1; i <= x; i += 2)
        PrintLine(i, biggerHalf);
    for (int i = x - 2; i > 0;i -= 2)
        PrintLine(i, biggerHalf);
    return retval;
}

int main() 
{
    PrintDiamond(17);
}

