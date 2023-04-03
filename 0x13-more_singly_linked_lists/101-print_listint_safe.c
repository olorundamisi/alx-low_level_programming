#include "lists.h"


/**
 * print_listint_safe - prints a listint_t list
 * @head: pointer to the first element of the list
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i;
	listint_t *it = (listint_t *)head;

	i = 0;
	while (it && (it > it->next))
	{
		printf("[%p] %d\n", (void *)it, it->n);
		it = it->next;
		i++;
	}
	if (it)
	{
		printf("[%p] %d\n", (void *)it, it->n);
		printf("-> [%p] %d\n", (void *)it->next, it->next->n);
		i++;
	}
	return (i);
}
