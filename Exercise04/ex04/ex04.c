#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// what's this?
/* extern char** environ; */

void PrintEnvVariable(const char *var)
{
    // malloc and copy to new buffer since we don't want to actually edit env variables
    char* tempVar = malloc((strlen(var) + 1) * sizeof(char));
    strncpy(tempVar, var, strlen(var)); // probably defeats purpose of safe version
    char* name = strtok(tempVar, "=");
    char* value = strtok(NULL, "=");
    printf("Environment variable \"%s\" has the value \"%s\".\n", name, value);
    free(tempVar);
}

int main(int argc, char** argv, char** envp) {

    for (size_t i = 0; envp[i] != NULL; i++)
    {
        PrintEnvVariable(envp[i]);
    }
    return 0;
}
