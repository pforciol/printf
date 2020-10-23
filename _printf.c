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
	int i, j, k;
	specs_t specs[] = {
		{"c", store_char},
		{"s", store_string},
		{NULL, NULL}
	};
	char *temp;

	va_start(list, format);

	for (i = 0; format && format[i]; i++)
	{
		while (format[i] != '%' && format[i])
			_putchar(format[i]);

		if (format[i] == '%' && format[i + 1] != '%')
			for (j = 0; specs[j].spec; j++)
			{
				if (format[i + 1] == specs[j].spec[0])
				{
					temp = specs[j].func(list);
					k = 0;
					while (temp[k])
						_putchar(temp[k++]);


				}
			}
	}
	va_end(list);

	return (0);
}
