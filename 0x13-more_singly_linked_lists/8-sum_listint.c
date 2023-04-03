#include <stdlib.h>

#include "lists.h"


/**
 * sum_listint - sums all the data of a linked list
 * @head: pointer to the first element of the list
 * Return: sum of all the data
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *tmp;

	if (head == NULL)
		return (0);

	tmp = head;
	while (tmp != NULL)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}
	return (sum);
}
