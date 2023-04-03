#include "lists.h"


/**
 * is_visited - assert if a node in a linked list is visited
 * @node: pointer to node
 * @visited: list of visited nodes
 * @num: length of visited nodes
 * Return: 1 if is visited else return 0
 */

int is_visited(const listint_t *node, const listint_t **visited, int num)
{
	int i = 0;

	while (i < num)
	{
		if (node == visited[i])
			return (1);
		i++;
	}
	return (0);
}


/**
 * print_listint_safe - prints a listint_t list safely, even loops
 * @head: pointer to the first element of the list
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	int number_of_nodes = 0;
	const listint_t *visited[1024];

	while (head != NULL)
	{
		if (is_visited(head, visited, number_of_nodes))
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
		visited[number_of_nodes++] = head;

		printf("[%p] %d\n", (void *)head, head->n);

		head = head->next;
	}
	return (number_of_nodes);
}
