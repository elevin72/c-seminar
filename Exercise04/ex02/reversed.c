#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "reversed.h"

void PrintReversed(const char* sentence)
{
    size_t sentenceLength = strlen(sentence);
    size_t wordLength = 0;
    int i = sentenceLength - 1;
    while (i != -1) // 1 past the beginning of tha string
    {
        if (sentence[i] != ' ' || i == 0)
        {
            ++wordLength;
            --i;
        }
        if (sentence[i] == ' ' || i == -1)
        {
            // print word
            for (size_t j = 0; j < wordLength; ++j)
            {
                printf("%c", sentence[i + j + 1]);
            }
            printf("%c", ((i != -1) ? ' ' : '\n'));

            // eat up remaining whitespace
            while (sentence[i] == ' ' && i != 0)
            {
                --i;
            }

            // reset wordlength
            wordLength = 0;
        }
    }
}

