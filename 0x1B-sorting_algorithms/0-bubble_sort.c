/*
 * File: 0-bubble_sort.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "sort.h"

/**
 * swap_ints - Swap two integers. This procedure works for array elements
 *			   and regular ints alike.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in non-decreasing order using the
 *				 bubble sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size or length of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool is_bubbly = false;

	if (array == NULL || size <= 1)
		return;

	while (is_bubbly == false)
	{
		is_bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				is_bubbly = false;
			}
		}
		len--;
	}
}
