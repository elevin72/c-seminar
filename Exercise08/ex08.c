#include "puppies.h"
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    if (argc != 2)
    {
        printf("Usage: ./freePuppies path-to-zipped-archive\n");
        return 1;
    }
    
    UnzipPuppies(argv[1]);

    return 0;
}