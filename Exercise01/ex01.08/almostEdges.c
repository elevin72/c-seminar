#include <stdio.h>
#include <limits.h>



void AlmostEdges(int *result)
{
    int smallest, secondSmallest, biggest, secondBiggest, input;
    smallest = secondSmallest = INT_MAX;
    biggest = secondBiggest = INT_MIN;
    printf("Enter some numbers, end with 0\n");
    for (int count = 0;; ++count)
    {
        scanf(" %d", &input);
        if (input == 0)
        {
            if (count < 2)
            {
                printf("U r idjit\n");
                result[0] = result[1] = -1;
            }
            else
            {
                result[0] = secondSmallest;
                result[1] = secondBiggest;
            }
            break;
        }
        // deal with smallest
        if (input < smallest)
        {
            secondSmallest = smallest;
            smallest = input;
        }
        else if (input < secondSmallest)
        {
            secondSmallest = input;
        }
        //deal with largest
        if (input > biggest)
        {
            secondBiggest = biggest;
            biggest = input;
        }
        else if (input > secondBiggest)
        {
            secondBiggest = input;
        }

    }
}

int main()
{
    int result[2];
    AlmostEdges(result);
    printf("second smallest: %d\nsecond largest : %d\n", result[0], result[1]);
}

