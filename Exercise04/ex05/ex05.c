#include <stdio.h>

extern char** environ;

int StartsWith(const char* string, const char* prefix)
{
    for (size_t i = 0; prefix[i] != '\0'; ++i)
    {
        if (prefix[i] != string[i])
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {

    if (argc != 2)
    {
        printf("Usage: 'program-name' 'environment variable prefix'\n");
        return 1;
    }

    for (size_t i = 0; environ[i] != NULL; i++)
    {
        if (StartsWith(environ[i], argv[1]))
        printf("%s\n", environ[i]);
    }
    return 0;
}
