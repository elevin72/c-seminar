

void PrintReversed(const char* string)
{
    size_t stringLength = strlen(string);
    size_t wordLength = 0;
    int i = stringLength - 1;
    while (i != -1)
    {
        if (string[i] != ' ' || i == 0)
        {
            ++wordLength;
            --i;
        }
        if (string[i] == ' ' || i == -1) // string[i] == ' '
        {
            // print wod
            for (size_t j = 0; j < wordLength; ++j)
            {
                printf("%c", string[i + j + 1]);
            }
            printf("%c", ((i != -1) ? ' ' : '\n'));
            fflush(stdout);
            while (string[i] == ' ' && i != 0)
            {
                --i;
            }
            wordLength = 0;
        }
    }
}

int main()
{
    PrintReversed("This is a sentence");
}
