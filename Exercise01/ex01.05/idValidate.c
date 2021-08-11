#include <stdbool.h>
#include <stdio.h>

#define MAX_ID 999999999
#define ID_LENGTH_NO_CHECK_DIGIT 8 // this feels silly

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

bool CheckID(unsigned int id)
{
    if (id > MAX_ID)
        return false;
    int checkDigit = id % 10;
    if (checkDigit == GetCheckDigit(id))
        return true;
    else
        return false;
}

int main()
{
    unsigned int id;
    printf("Please enter an ID number\n");
    scanf(" %u", &id);
    printf(CheckID(id) ? "Valid\n" : "Not Valid\n");
}
