#include <stdio.h>

#include "main.h"


/**
 * print_diagsums - prints the sum of the two
 * diagonals of a square matrix of integers.
 * @a: array pointer
 * @size: size
 */


void print_diagsums(int *a, int size)
{
	int firstsum = 0, secondsum = 0;
	int i, j;
	int *arr = (int *) a;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				firstsum += arr[i * size + j];

			if ((i + j) == (size - 1))
				secondsum += arr[i * size + j];
			j++;
		}

		i++;
	}
	printf("%d, %d\n", firstsum, secondsum);
}
