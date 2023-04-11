#ifndef PRINTF_CLASS
#define PRINTF_CLASS



#include "main.h"


/**
 * printf_class - print the class of ELF header file
 * @elf_identifier: char pointer containing the ELF class
 */

void printf_class(unsigned char *elf_identifier)
{
	printf("  Class:                             ");

	switch (elf_identifier[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_identifier[EI_CLASS]);
	}
}


#endif /* PRINTF_CLASS */
