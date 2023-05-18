/*
 * File: 1-dlistint_len.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * dlistint_len - Count the number of elements in a `dlistint_t' list.
 * @h: The head node of the `dlistint_t' list.
 *
 * Return: The number of elements in the doubly linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;

		h = h->next;
	}

	return (nodes);
}
