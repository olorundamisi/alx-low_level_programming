#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int c;

	c = 0;

	while (c <= 9)
	{
		putchar((c % 10) + '0');
		c++;
	}
	putchar('\n');

	return (0);
}
