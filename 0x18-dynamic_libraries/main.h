#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
int _abs(int n);
int _atoi(char *s);
int _isalpha(int c);
int _isdigit(int c);
int _islower(int c);
int _isupper(int c);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
unsigned int _strspn(char *s, char *accept);
void _puts(char *s);

#endif /* MAIN_H */
