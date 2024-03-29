#include "main.h"


/**
 * print_binary - print the binary representation of a number `n`
 * @n: number n to be converted
 * Return: void
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	_putchar((n & 1) + '0');
}
