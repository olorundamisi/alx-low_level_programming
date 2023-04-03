#include <stdio.h>
#include <stdlib.h>

#include "lists.h"


/**
 * print_listint - print all elements of a linked list
 * @h: pointer to the first element of the linked list
 * Return: number of nodes in the linked list
 */

size_t print_listint(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
