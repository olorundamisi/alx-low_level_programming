#include "main.h"


/**
 * _strlen - Return the length of input string
 * @str: char *
 * Return: length of string s;
 */

int _strlen(char *str)
{
	int size;

	size = 0;
	while (str[size] != 0)
		++size;

	return (size);
}
