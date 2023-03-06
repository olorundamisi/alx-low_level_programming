#include <stdio.h>

#include "main.h"


/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
    char *s = "hello, world";
    char *f = "";
    char *t;

    t = _strpbrk(s, f);
    printf("%s\n", t);

    return (0);
}
