#ifndef ELF_FILE_UTILS_H
#define ELF_FILE_UTILS_H


#include "main.h"


/**
 * assert_elf_file - Assert that the file is a valid ELF file
 * @e_ident: ELF Identifier
 * Description: If ELF file assert fails, return exit code 98.
 */

void assert_elf_file(unsigned char *e_ident)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 &&
				e_ident[idx] != 'E' &&
				e_ident[idx] != 'L' &&
				e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}




/**
 * close_elf_file - Close an ELF file.
 * @elf: File Descriptor for our ELF file.
 * Desc: If ELF file close fails, return exit code 98
 */
void close_elf_file(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


#endif /* ELF_FILE_UTILS_H */
