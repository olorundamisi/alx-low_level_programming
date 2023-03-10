#include <stdio.h>

#include "main.h"

/**
 * times_table - prints 9 timestable
 *
 * Return: 0
 */

void times_table(void)
{
	int i, j, first, last, mult;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			mult = i * j;
			first = mult / 10;
			last = mult % 10;
			if (first == 0)
			{
				if (j >= 1)
				{
					_putchar(first + ' ');
				}
				_putchar(last + '0');
				if (j != 9)
				{
					_putchar(',');
					_putchar(' ');
				}
				continue;
			}
			_putchar(first + '0');
			_putchar(last + '0');
			if (j != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
