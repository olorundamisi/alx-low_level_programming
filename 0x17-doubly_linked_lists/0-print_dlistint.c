/*
 * File: 0-print_dlistint.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * print_dlistint - Print all the elements in a `dlistint_t' list.
 * @h: The head node of the `dlistint_t' list.
 *
 * Return: The number of nodes in the doubly linked list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;

		printf("%d\n", h->n);

		h = h->next;
	}

	return (nodes);
}
