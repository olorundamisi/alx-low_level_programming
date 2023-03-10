#include <stdio.h>

#include "main.h"


/**
 * print_to_98 - print from n to 98
 *
 * @n: range
 *
 * Return: void
 */


void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i == 98)
			{
				printf("%d", i);
				continue;
			}
			printf("%d, ", i);
		}
		putchar('\n');
	}
	else
	{
		for (i = n; i >= 98; i--)
		{
			if (i == 98)
			{
				printf("%d", i);
				continue;
			}
			printf("%d, ", i);
		}
		putchar('\n');
	}
}
