/*
 * File: 3-add_dnodeint_end.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * add_dnodeint_end - Add a new node to the end of a `dlistint_t' list.
 * @head: A pointer to the head node of the `dlistint_t' list.
 * @n: The integer value to put in the new node.
 *
 * Return: If the function fails - NULL.
 *         Else - The address of the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
