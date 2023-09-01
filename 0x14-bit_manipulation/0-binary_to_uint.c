#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a binary string.
 * Return: The converted number, or 0 if invalid or NULL.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;

    if (!b)
        return 0;

    while (*b)
    {
        if (*b != '0' && *b != '1')
            return 0;

        result = result * 2 + (*b - '0');
        b++;
    }

    return result;
}
