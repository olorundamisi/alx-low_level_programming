#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list
 * @head: pointer to the first element of the list
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i;
	listint_t *iter = (listint_t *)head;

	i = 0;
	while (iter && iter > iter->next)
	{
		printf("[%p] %d\n", (void *)iter, iter->n);
		iter = iter->next;
		i++;
	}
	if (iter)
	{
		printf("[%p] %d\n", (void *)iter, iter->n);
		printf("-> [%p] %d\n", (void *)iter->next, iter->next->n);
		i++;
	}
	return (i);
}

