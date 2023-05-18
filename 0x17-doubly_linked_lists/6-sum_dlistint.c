/*
 * File: 6-sum_dlistint.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "lists.h"

/**
 * sum_dlistint - Sum all the data of a `dlistint_t' list.
 * @head: The head node of the `dlistint_t' list.
 *
 * Return: The sum of all the data.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
