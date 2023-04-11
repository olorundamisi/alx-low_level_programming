#include "main.h"


/**
 * assert_elf_file - Assert that the file is a valid ELF file
 * @elf_identifier: ELF Identifier
 * Desc: If ELF file assert fails, return exit code 98.
 */

void assert_elf_file(unsigned char *elf_identifier)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (elf_identifier[idx] != 127 &&
				elf_identifier[idx] != 'E' &&
				elf_identifier[idx] != 'L' &&
				elf_identifier[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
