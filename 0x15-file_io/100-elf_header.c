#include "main.h"


/* Function Prototypes */
void assert_elf_file(unsigned char *e_ident);
void printf_magic(unsigned char *e_ident);
void printf_class(unsigned char *e_ident);
void printf_data(unsigned char *e_ident);
void printf_version(unsigned char *e_ident);
void printf_os_abi(unsigned char *e_ident);
void printf_abi_version(unsigned char *e_ident);
void printf_type(unsigned int e_type, unsigned char *e_ident);
void printf_entry_point_addr(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);


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

	check_elf(e_hdr->e_ident);
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


/**
 * printf_os_abi - print the OS/ABI of ELF header file
 * @e_ident: char pointer containing the ELF OS/ABI Information
 */

void printf_os_abi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}


/**
 * printf_abi_version - print the ABI version of ELF header file
 * @e_ident: char pointer containing ABI Version of the ELF file
 */

void printf_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}


/**
 * printf_type - print the type of ELF header
 * @e_type: Type of ELF header file
 * @e_ident: char pointer containing the ELF data
 */

void printf_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}


/**
 * printf_entry_point_addr - print Entry Point Address for the ELF Header file
 * @e_entry: ELF entry point address
 * @e_identifier: char pointer containing ELF data
 */

void printf_entry_point_addr(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
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

