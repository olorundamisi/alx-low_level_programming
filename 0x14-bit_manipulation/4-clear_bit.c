#include "main.h"


/**
 * clear_bit - clear the bit at index of a given unsigned int
 * @n: number to be converted
 * @index: index of bit to be cleared
 * Return: 1 if the bit was cleared, -1 if an error occurs
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	int bit;
	unsigned long int mask;

	if (index > sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = ~(1 << index);
	bit = *n & mask;
	*n = bit;

	return (1);
}
