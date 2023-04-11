#include "main.h"
#include "elf_header_helper.h"
#include "elf_file_utils.h"
#include "elf_print_utils.h"


/**
 * main - print information contained in ELF header at the beginnning of
 *        an ELF file
 * @argc: argument count - number of arguments
 * @argv: argument vector - array containing arguments
 * Return: integer 0 on success
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *e_hdr;
	int file_open, file_read;

	file_open = open(argv[1], O_RDONLY);
	if (file_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98); }

	e_hdr = malloc(sizeof(Elf64_Ehdr));
	if (e_hdr == NULL)
	{
		close_elf_file(file_open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98); }

	file_read = read(file_open, e_hdr, sizeof(Elf64_Ehdr));
	if (file_read == -1)
	{
		free(e_hdr);
		close_elf_file(file_open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98); }

	assert_elf_file(e_hdr->e_ident);
	printf("ELF Header:\n");
	printf_magic(e_hdr->e_ident);
	printf_class(e_hdr->e_ident);
	printf_data(e_hdr->e_ident);
	printf_version(e_hdr->e_ident);
	printf_os_abi(e_hdr->e_ident);
	printf_abi_version(e_hdr->e_ident);
	printf_type(e_hdr->e_type, e_hdr->e_ident);
	printf_entry_point_addr(e_hdr->e_entry, e_hdr->e_ident);

	free(e_hdr);
	close_elf_file(file_open);

	return (0);
}


/**
 * printf_magic - print the magic numbers of ELF header file
 * @e_ident: char pointer containing ELF magic numbers
 */

void printf_magic(unsigned char *e_ident)
{
	int idx;

	printf("  Magic:   ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


/**
 * printf_class - print the class of ELF header file
 * @e_ident: char pointer containing the ELF class
 */

void printf_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * printf_data - print the data of ELF header file
 * @e_ident: char pointer containing the ELF data
 */

void printf_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * printf_version - print the version of ELF header file
 * @e_ident: char pointer containing the ELF version
 */
void printf_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
