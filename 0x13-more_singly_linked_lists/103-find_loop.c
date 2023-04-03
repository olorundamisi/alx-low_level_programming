#include "lists.h"


/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the first element of the list
 * Return: pointer to the node where the loop starts
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head;
	listint_t *hare = head;

	if (head == NULL)
		return (NULL);

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			break;
	}

	if (hare == NULL || hare->next == NULL)
		return (NULL);

	tortoise = head;
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}

	return (tortoise);
}
