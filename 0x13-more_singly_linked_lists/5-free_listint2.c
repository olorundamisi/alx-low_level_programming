#include <stdlib.h>

#include "lists.h"


/**
 * free_listint2 - frees a listint_t list
 * @head: pointer to the first element of the linked list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;

		free(tmp);
	}

	*head = NULL;
}
