#include <stdio.h>
#include <string.h>

#include "morewarmup.h"

int Terminated(char *string) 
{
    if (strncmp(string, "Q", LINE_LENGTH) == 0 || strncmp(string, "q", LINE_LENGTH) == 0) 
        return 1;
    else
        return 0;
}

void RemoveNewLine(char *string) 
{
    int newLineIndex = strlen(string) - 1;
    if (string[newLineIndex] == '\n')
        string[newLineIndex] = '\0';
}

int main()
{
    char buffer[LINE_LENGTH];
    for (;;)
    {
        fgets(buffer, LINE_LENGTH, stdin);
        RemoveNewLine(buffer);
        if (Terminated(buffer)) 
        {
            printf("Goodbye\n");
            break;
        }
        if (buffer[0] >= 'a' && buffer[0] <= 'z') 
        {
            buffer[0] -= 32;
        }
        printf("%c\n",buffer[0]);
    }
    return 0;
}
