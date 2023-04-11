#ifndef ELF_HEADER_HELPER_H
#define ELF_HEADER_HELPER_H


void assert_elf_file(unsigned char *e_ident);
void printf_magic(unsigned char *e_ident);
void printf_class(unsigned char *e_ident);
void printf_data(unsigned char *e_ident);
void printf_version(unsigned char *e_ident);
void printf_os_abi(unsigned char *e_ident);
void printf_abi_version(unsigned char *e_ident);
void printf_type(unsigned int e_type, unsigned char *e_ident);
void printf_entry_point_addr(
		unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);


#endif /* ELF_HEADER_HELPER_H */
