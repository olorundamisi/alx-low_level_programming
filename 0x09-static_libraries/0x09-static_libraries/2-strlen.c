#include <stdio.h>

#include "main.h"


/**
 * _strlen - prints length of string
 *
 * @s: pointer
 *
 * Return: count (length of string)
 */

int _strlen(char *s)
{
	int count = 0;

	for (; *s != '\0'; s++)
	{
		count++;
	}

	return (count);
}
