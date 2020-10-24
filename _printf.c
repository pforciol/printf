#include "holberton.h"

/**
 * spec_eng - Calls the correct print function and returns a string
 *
 * @list: the va_list object
 * @data: the parsed complete specifier
 *
 * Return: a string
 */

char *spec_eng(va_list list, spec_data_t *data)
{
	specs_t specs[] = {
		{'c', store_char},
		{'s', store_string},
	};
	int i;

	for (i = 0; specs[i].spec; i++)
	{
		if (data->spec == specs[i].spec)
			return (specs[i].func(list));
	}

	return (NULL);
}

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
	int i = 0, len = 0;
	char *buffer = NULL;
	char *tmp;
	spec_data_t *data;

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
			data = parse_spec(format + i);
			if (data->len == 0)
				buffer = _strcat(buffer, "%");
			else if (data->spec == '%')
			{
				buffer = _strcat(buffer, "%");
				i++;
			}
			else if (data)
			{
				tmp = spec_eng(list, data);
				buffer = _strcat(buffer, tmp);
				i += data->len;
			}
			free_spec_data(data);
		}
		i++;
	}

	va_end(list);
	if (_strlen(buffer) == 0)
	{
		_putchar('\0');
		len = 1;
	}
	else
	{
		_puts(buffer);
		len = _strlen(buffer);
	}
	free(buffer);
	return (len);
}
