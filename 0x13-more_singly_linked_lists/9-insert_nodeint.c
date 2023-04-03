#include <stdlib.h>

#include "lists.h"


/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the first element of the list
 * @index: index to insert the new node
 * @n: data for the new node
 * Return: address of the new node, or NULL if failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *tmp;

	if (head == NULL)
		return (NULL);

	if (index == 0)
	{
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			return (NULL);

		new->n = n;
		new->next = *head;
		*head = new;

		return (new);
	}

	tmp = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (tmp == NULL)
			return (NULL);
		tmp = tmp->next;
	}

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = tmp->next;
	tmp->next = new;

	return (new);
}
