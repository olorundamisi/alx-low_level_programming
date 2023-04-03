#include <stdlib.h>

#include "lists.h"


/**
 * delete_nodeint_at_index - deletes node at index
 * @head: pointer to the first element of the list
 * @index: index of the node to delete
 * Return: 1 if it succeeds, -1 if it fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp;
	listint_t *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	tmp = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp->next = tmp2->next;

	free(tmp2);

	return (1);
}
