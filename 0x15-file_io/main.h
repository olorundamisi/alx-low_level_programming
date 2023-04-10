#ifndef MAIN_H
#define MAIN_H


#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int _putchar(char c);
int append_text_to_file(const char *filename, char *content);
int create_file(const char *filename, char *content);
ssize_t read_textfile(const char *filename, size_t letters);


#endif /* MAIN_H */
