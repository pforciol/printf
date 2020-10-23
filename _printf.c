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
	int i = 0, j, len = 0;
	char *buffer = NULL;
	specs_t specs[] = {
		{"c", store_char},
		{"s", store_string},
		{NULL, NULL}
	};

	va_start(list, format);

	if (!format)
		return (-1);

	while (format[len])
	{
		len++;
	}
	while (format[i] && i < len)
	{
		while (format[i] && format[i] != '%')
		{
			buffer = _charcat(buffer, format[i]);
			i++;
		}

		if (format[i] == '%' && format[i + 1] != '%')
		{
			for (j = 0; specs[j].spec; j++)
			{
				if (format[i + 1] == specs[j].spec[0])
				{
					buffer = _strcat(buffer, specs[j].func(list));
				}
			}
		}
		i++;
	}
	va_end(list);

	_puts(buffer);
	return (_strlen(buffer));
}
