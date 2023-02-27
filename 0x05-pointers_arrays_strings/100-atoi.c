#include "main.h"


/**
 * *_atoi - convert string to number.
 * @s: string reference
 *
 * Return: conversion
 */


int _atoi(char *s)
{
	int res = 0;
	int sig = -1;
	int brk = 0;

	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			sig = sig * -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10;
			res = res - (s[i] - '0');
			brk = 1;
		}
		else if (brk == 1)
		{
			break;
		}
	}
	res *= sig;

	return (res);
}
