/*
 * File: 2-add_dnodeint.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * add_dnodeint - Add a new node to the beginning of a `dlistint_t' list.
 * @head: A pointer to the head node of the `dlistint_t' list.
 * @n: The integer value to put in the new node.
 *
 * Return: If the function fails - NULL.
 *         Else - The address of the new node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}
