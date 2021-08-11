#include <stdio.h>

#include "fixID.h"

int GetCheckDigit(unsigned int id)
{
    int currentDigit, twiceCurrentDigit, sum = 0, retval;
    for (int i = 0; i < ID_LENGTH_NO_CHECK_DIGIT; ++i)
    {
        currentDigit = id % 10; 
        id = id / 10;
        if (i % 2 == 0)
        {
            twiceCurrentDigit = currentDigit * 2;
            currentDigit = twiceCurrentDigit > 9 ? (twiceCurrentDigit) - 9 : twiceCurrentDigit;
        }
        sum += currentDigit;
    }
    retval = 10 - (sum % 10);
    return retval != 10 ? retval : 0;
}


int main()
{
    unsigned int id;
    printf("Please enter 8 digits of an ID number\n");
    scanf(" %u", &id);
    printf("The check digit is: %u\n", GetCheckDigit(id));
}
