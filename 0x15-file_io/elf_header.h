#ifndef ELF_HEADER_H
#define ELF_HEADER_H


/* main header file */
#include "main.h"

/* supplementary header files for 100-elf_header.c */
#include "assert_elf_file.h"
#include "printf_magic.h"
#include "printf_class.h"
#include "printf_data.h"
#include "printf_version.h"
#include "printf_os_abi.h"
#include "printf_abi_version.h"
#include "printf_type.h"
#include "printf_entry_point_addr.h"
#include "close_elf_file.h"


void assert_elf_file(unsigned char *elf_identifier);
void printf_magic(unsigned char *elf_identifier);
void printf_class(unsigned char *elf_identifier);
void printf_data(unsigned char *elf_identifier);
void printf_version(unsigned char *elf_identifier);
void printf_os_abi(unsigned char *elf_identifier);
void printf_abi_version(unsigned char *elf_identifier);
void printf_type(unsigned int elf_type, unsigned char *elf_identifier);
void printf_entry_point_addr(unsigned long int elf_entry,
		unsigned char *elf_identifier);
void close_elf_file(int elf);


#endif /* ELF_HEADER_H */
