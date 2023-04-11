#ifndef PRINTF_ABI_VERSION_H
#define PRINTF_ABI_VERSION_H


#include "main.h"


/**
 * printf_abi_version - print the ABI version of ELF header file
 * @elf_identifier: char pointer containing ABI Version of the ELF file
 */

void printf_abi_version(unsigned char *elf_identifier)
{
	printf("  ABI Version:                       %d\n",
			elf_identifier[EI_ABIVERSION]);
}


#endif /* PRINTF_ABI_VERSION_H */
