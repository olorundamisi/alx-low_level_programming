#include "main.h"


/**
 * _memset - fills memory with a constant byte.
 *
 * @s: memory area pointer.
 * @b: constant byte to be filled with
 * @n: number of bytes to be filled
 *
 * Return: char*
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
