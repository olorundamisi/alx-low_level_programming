#include "main.h"


/**
 * flip_bits - number of bits to flip
 * @n: number to convert
 * @m: number of bits to flip
 * Return: cnt = number of bits needed to flip to obtain m
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask;
	unsigned int i, cnt;

	cnt = 0, mask = 1;
	for (i = 0; i < sizeof(unsigned long int) * 8; i++)
	{
		if ((n & mask) != (m & mask))
		{
			cnt++;
		}
		mask = mask << 1;
	}

	return (cnt);
}
