#include "main.h"


/**
 * _printf - Given its many usecases, `_printf` selects the appropriate function to use to printf.
 * @format: object string to format
 * Return: the length of the formatted string.
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	unsigned int len = 0;
	int i, j;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	
	return (len);
}
