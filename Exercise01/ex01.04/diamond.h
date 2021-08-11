
/**
 * Prints a character a given number of times.
 *
 * @param c The character to be printed
 * @param n The number of times to print the character
 *
 */
void PrintChar(char c, int n);

/**
 * Prints a line of the diamond
 *
 * @param spaces number of spaces in line
 * @param stars number of stars in line
 *
 */
void PrintLine(int spaces, int stars);


/**
 * Prints a diamond of stars
 * 
 *
 * @param width width of diamond. This parameter should be an odd int
 * @return 0 on success, -1 if width was even or negative
 *
 */
int PrintDiamond(int width);
