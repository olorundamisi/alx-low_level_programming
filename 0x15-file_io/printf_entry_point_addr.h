#ifndef PRINTF_ENTRY_POINT_ADDR_H
#define PRINTF_ENTRY_POINT_ADDR_H


#include "main.h"


/**
 * printf_entry - print Entry Point Address for the ELF Header file
 * @elf_entry: ELF entry point address
 * @elf_identifier: char pointer containing ELF data
 */

void printf_entry(unsigned long int elf_entry, unsigned char *elf_identifier)
{
	printf("  Entry point address:               ");

	if (elf_identifier[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_identifier[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}


#endif /* PRINTF_ENTRY_POINT_ADDR_H */
