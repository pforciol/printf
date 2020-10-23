#include "holberton.h"

/**
 * _printf - entry point for our main function
 *
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, j = 0;
	specs_t specs[] = {
		{"c", print_char},
		{"s", print_string}
	}

	va_start(list, format);

	while (format && format[i])
	{
		j = 0;
		while (specs[j].spec)
		{
			if (format[i] == specs[j].spec[0])
			{
				specs[j].func(list);
			}
			j++;
		}
		i++;
	}

	va_end(list);
	return (0);
}
