#include <stdio.h>
#include "sum.h"


int main()
{
    int arr[] = {1,2,3,4,5};
    printf("%d\n", sum(arr, sizeof(arr) / sizeof(int)));
}
