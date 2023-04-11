#include "main.h"


/**
 * printf_data - print the data of ELF header file
 * @elf_identifier: char pointer containing the ELF data
 */

void printf_data(unsigned char *elf_identifier)
{
	printf("  Data:                              ");

	switch (elf_identifier[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_identifier[EI_CLASS]);
	}
}
