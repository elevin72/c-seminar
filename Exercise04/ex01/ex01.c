#include <string.h>
#include <stdio.h>

void ReverseString(char* str)
{
    int len = strlen(str) - 1;
    for (int i = len; i != -1; --i) // -1 is 1 past beginning of string
    {
        printf("%c",str[i]);
    }
    printf("\n");
}

int main()
{
    char str[80];
    scanf("%s", str);
    ReverseString(str);
}
