#include <stdio.h>

void PrintReversed()
{
    int input;
    scanf(" %d", &input);
    if (input == 0)
    {
        printf("0\n");
        return;
    }
    else
    {
        PrintReversed();
    }
    printf("%d\n", input);
}

int main()
{
    PrintReversed();
}
