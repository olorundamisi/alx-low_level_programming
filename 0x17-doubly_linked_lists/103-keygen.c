/*
 * File: 103-keygen.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generate and output password keys for the crackme5 executable.
 * @argc: Argument Count  - The number of arguments supplied to the program.
 * @argv: Argument Vector - An array of pointers to the arguments supplied.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char **argv)
{
	char *codex, key[7];
	int size = strlen(argv[1]), tmp;
	int i;

	codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	tmp = (size ^ 59) & 63;
	key[0] = codex[tmp];

	tmp = 0;
	for (i = 0; i < size; i++)
		tmp += argv[1][i];
	key[1] = codex[(tmp ^ 79) & 63];

	tmp = 1;
	for (i = 0; i < size; i++)
		tmp *= argv[1][i];
	key[2] = codex[(tmp ^ 85) & 63];

	tmp = 0;
	for (i = 0; i < size; i++)
	{
		if (argv[1][i] > tmp)
			tmp = argv[1][i]; }
	srand(tmp ^ 14);
	key[3] = codex[rand() & 63];

	tmp = 0;
	for (i = 0; i < size; i++)
		tmp += (argv[1][i] * argv[1][i]);
	key[4] = codex[(tmp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		tmp = rand();
	key[5] = codex[(tmp ^ 229) & 63];
	key[6] = '\0';
	printf("%s", key);

	return (0);
}
