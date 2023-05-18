/*
 * File: 5-get_dnodeint.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * get_dnodeint_at_index - Get the nth node in a `dlistint_t' list.
 * @head: The head node of the `dlistint_t' list.
 * @index: The index of the node to locate.
 *
 * Return: If the node does not exist - NULL.
 *         Else - the address of the located node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index != 0)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;

		index--;
	}

	return (head);
}
