/*
 * File: 7-insert_dnodeint.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert a new node in a `dlistint_t' list at a
 *                            given position.
 * @h: A pointer to the head node of the `dlistint_t' list.
 * @idx: The position to insert the new node.
 * @n: The integer value to put in the new node.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = *h, *new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL); }

	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = tmp;
	new->next = tmp->next;

	tmp->next->prev = new;
	tmp->next = new;

	return (new);
}
