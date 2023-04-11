#include "main.h"


/**
 * printf_version - print the version of ELF header file
 * @elf_identifier: char pointer containing the ELF version
 */

void printf_version(unsigned char *elf_identifier)
{
	printf("  Version:                           %d",
			elf_identifier[EI_VERSION]);

	switch (elf_identifier[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
