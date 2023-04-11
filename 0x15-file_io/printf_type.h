#include "main.h"


/**
 * printf_type - print the type of ELF header
 * @elf_type: Type of ELF header file
 * @elf_identifier: char pointer containing the ELF data
 */

void printf_type(unsigned int elf_type, unsigned char *elf_identifier)
{
	if (elf_identifier[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
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
		default:
			printf("<unknown: %x>\n", elf_type);
	}
}
