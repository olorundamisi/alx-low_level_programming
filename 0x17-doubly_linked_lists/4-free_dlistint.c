/*
 * File: 4-free_dlistint.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * free_dlistint - Free a linked `dlistint_t' list.
 * @head: The head node of the `dlistint_t' list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;

		free(head);

		head = tmp;
	}
}
