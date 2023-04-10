#include "main.h"


/**
 * binary_to_uint - convert a binary number `b` to an unsigned int `n`
 * @b: pointer to string of binary digits
 * Return: the number `n` of type: unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int n;

	if (!b)
		return (0);

	i = n = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '1')
			n = (n * 2) + 1;
		else if (b[i] == '0')
			n *= 2;
		else
			return (0);

		i++;
	}
	return (n);
}
