#include <stddef.h>

/**
 * 80 is standard length of a line
 */
#define LENGTH 80

/**
 * calculates length of a c-style string
 *
 * @param str Pointer to null terminated buffer of bytes
 * @return length of string, not including null character
 */
size_t MyStrlen(char* str);

