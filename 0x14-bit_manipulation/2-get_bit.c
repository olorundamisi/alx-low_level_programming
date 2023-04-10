#include "main.h"


/**
 * get_bit - get the value of a bit at a supplied index
 * @n: number to convert
 * @index: index of bit to be checked
 * Return: value of bit at index or return -1 if there's an error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit, mask;

	if (index > sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = 1 << index;
	bit = n & mask;
	bit = bit >> index;

	return (bit);
}
