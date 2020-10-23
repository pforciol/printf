#include "holberton.h"

/**
 * spec_eng - Calls the correct print function and returns a string
 *
 * @list: the va_list object
 * @str: the requested specifier
 * @prec: the requested precision
 *
 * Return: a string
 */

char *spec_eng(va_list list, char *str, char *prec)
{
	specs_t specs[] = {
		{"c", store_char},
		{"s", store_string},
		{NULL, NULL}
	};
	int i;

	if (str[0] == '%')
		return ("%");

	for (i = 0; specs[i].spec; i++)
	{
		if (str[0] == specs[i].spec[0])
			return (specs[i].func(list, prec));
	}

	return (NULL);
}

/**
 * get_spec - gets the specifier of the current parameter
 *
 * @
 */

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

	len = _strlen((char *)format);
	while (format[i] && i < len)
	{
		while (format[i] && format[i] != '%')
		{
			buffer = _charcat(buffer, format[i]);
			i++;
		}

		if (format[i] == '%')
		{
			for (j = 0; specs[j].spec; j++)
			{
				if (format[i + 1] == specs[j].spec[0])
				{
					buffer = _strcat(buffer, specs[j].func(list));
					while (format[i] != ' ' && format[i])
						i++;
				}
			}
		}
		i++;
	}
	va_end(list);
	_puts(buffer);
	len = _strlen(buffer);
	free(buffer);
	return (len);
}
