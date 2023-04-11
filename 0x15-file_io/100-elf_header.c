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

	assert_elf_file(elf_header->elf_identifier);
	printf("ELF Header:\n");
	printf_magic			(elf_header->elf_identifier);
	printf_class			(elf_header->elf_identifier);
	printf_data				(elf_header->elf_identifier);
	printf_version			(elf_header->elf_identifier);
	printf_os_abi			(elf_header->elf_identifier);
	printf_abi_version		(elf_header->elf_identifier);
	printf_type				(elf_header->elf_type, elf_header->elf_identifier);
	printf_entry_point_addr	(elf_header->elf_entry, elf_header->elf_identifier);

	free(elf_header);
	close_elf_file(file_open);

	return (0);
}
