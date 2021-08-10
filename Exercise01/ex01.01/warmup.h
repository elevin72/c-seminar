/**
 * Standard line length is 80
 */
#define LINE_LENGTH 3

/**
 * Decides if the program should be terminated or not yet, based on the
 * null-terminated string passed
 *
 * @param string The string that is possibly a termination string
 * @return 1 for terminated, 0 for not terminated
 *
 */
int Terminated(char *string);

/**
 * If the final character in the string is a newline, that chracter is replaced
 * by a '\0'
 *
 * @param string The string that may have its newline removed
 */
void RemoveNewLine(char *string);
