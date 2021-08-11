#include "stdbool.h"

/**
 * Maximal value for an ID number
 */
#define MAX_ID 999999999

/**
 * Maximal length of a an ID, not including the check digit
 */
#define ID_LENGTH_NO_CHECK_DIGIT 8 // this feels silly

/**
 * Checks whether an ID number is valid or not
 * @param id A 9 digit positive integer, representing an ID number inclusing
 * it's check digit
 * @return true if ID is valid, false if invalid. Invalid means incorrect check
 * digit or ID number was more than 9 digits
 */
bool CheckID(unsigned int id);

/**
 * Calculates the check digit for an 8 digit ID number. Invalid input is UB.
 * @param id An 8 digit postive integer, representing an ID number
 * @return The check digit that will make this a valid ID
 */
int GetCheckDigit(unsigned int id);
