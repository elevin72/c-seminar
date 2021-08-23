#include <stdio.h>
#include <regex.h>

int main(int argc, char** argv) {

    for (size_t i = 1; argv[i] != NULL; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    printf("There are %d arguments\n", argc - 1);
    size_t flags = 0;
    size_t uppercaseCounter = 0;
    size_t lowercaseCounter = 0;
    regex_t lowerRegex, upperRegex;
	regcomp(&lowerRegex, "[^A-Z]", REG_EXTENDED);
	regcomp(&upperRegex, "[^a-z]", REG_EXTENDED);
    for (size_t i = 1; argv[i] != NULL; i++)
    {
        if (regexec(&lowerRegex, argv[i], 0, NULL, 0) == 0)
        {
            printf("lowercase++\n");
            ++lowercaseCounter;
        }
        if (regexec(&upperRegex, argv[i], 0, NULL, 0) == 0)
        {
            printf("uppercase++\n");
            ++uppercaseCounter;
        }
        if (argv[i][0] == '-' || argv[i][0] == '/')
        {
            flags++;
        }
    }
    printf("There are %zu flags\n", flags);
    printf("There are %zu lowercase params\n", lowercaseCounter);
    printf("There are %zu uppercase params\n", uppercaseCounter);
    return 0;
}


