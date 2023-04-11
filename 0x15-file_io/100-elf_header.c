#include "elf_header.h"


/**
 * main - print information contained in ELF header at the beginnning of
 *        an ELF file
 * @argc: argument count - number of arguments
 * @argv: argument vector - array containing arguments
 * Return: integer
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *elf_header;
	int file_open, file_read;

	file_open = open(argv[1], O_RDONLY);
	if (file_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98); }

	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		close_elf_file(file_open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98); }

	file_read = read(file_open, elf_header, sizeof(Elf64_Ehdr));
	if (file_read == -1)
	{
		free(elf_header);
		close_elf_file(file_open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98); }

	assert_elf_file(elf_header->e_ident);
	printf("ELF Header:\n");
	printf_magic			(elf_header->e_ident);
	printf_class			(elf_header->e_ident);
	printf_data				(elf_header->e_ident);
	printf_version			(elf_header->e_ident);
	printf_os_abi			(elf_header->e_ident);
	printf_abi_version		(elf_header->e_ident);
	printf_type				(elf_header->e_type, elf_header->e_ident);
	printf_entry_point_addr	(elf_header->e_entry, elf_header->e_ident);

	free(elf_header);
	close_elf_file(file_open);

	return (0);
}
