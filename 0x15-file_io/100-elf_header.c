#include "main.h"


/**
 * get_type - get the file type
 * @ehdr: ptr to struct of ELF header and features
 */

void get_type(Elf64_Ehdr *ehdr)
{
	printf("%-35s", "Type:");
	switch (ehdr->e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
	}
}


/**
 * main - entry point of program
 * @argc: argument count - number of arguments
 * @argv: argument vector - array containing arguments
 * Return: 1 or -1
 */

int main(int argc, char *argv[])
{
	printf("argc:%d, argv:%p\n", argc, (void *)*argv);

	return (1);
}
