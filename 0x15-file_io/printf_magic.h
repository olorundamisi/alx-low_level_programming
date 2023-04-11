#ifndef PRINTF_MAGIC_H
#define PRINTF_MAGIC_H


#include "main.h"


/**
 * printf_magic - print the magic numbers of ELF header file
 * @elf_identifier: char pointer containing ELF magic numbers
 */

void printf_magic(unsigned char *elf_identifier)
{
	int idx;

	printf("  Magic:   ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", elf_identifier[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


#endif /* PRINTF_MAGIC_H */
