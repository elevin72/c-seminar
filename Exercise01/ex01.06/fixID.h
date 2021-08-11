
/**
 * Maximal length of a an ID, not including the check digit
 */
#define ID_LENGTH_NO_CHECK_DIGIT 8 // this feels silly

/**
 * Calculates the check digit for an 8 digit ID number. Invalid input is UB.
 * @param id An 8 digit postive integer, representing an ID number
 * @return The check digit that will make this a valid ID
 */
int GetCheckDigit(unsigned int id);
