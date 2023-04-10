#include "main.h"


/**
 * set_bit - set the value of a bit to 1
 * @n: number to convert
 * @index: index of bit to be set
 * Return: 1 if the bit is set, -1 if an error occurs
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	int bit;
	unsigned long int mask;

	if (index > sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = 1 << index;
	bit = *n | mask;
	*n = bit;

	return (1);
}
