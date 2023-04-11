#include "main.h"


/**
 * close_elf_file - Closes an ELF file.
 * @elf: file descriptor of our ELF file.
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
