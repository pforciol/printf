#include "holberton.h"

void add_to_buf(pf_buf_t *buffer, char to_add)
{
	if (buffer->index < buffer->len)
	{
		buffer->buf[buffer->index] = to_add;
		buffer->index += 1;
	}
	if (buffer->index == buffer->len)
	{
		write(1, buffer->buf, buffer->len);
		buffer->index = 0;
	}
}

/**
 * spec_eng - Calls the correct print function and returns a string
 *
 * @list: the va_list object
 * @data: the parsed complete specifier
 *
 * Return: a string
 */

int spec_eng(va_list list, spec_data_t *data, pf_buf_t *buffer)
{
	pf_buf_t *tmp;
	int len = 0, i, j = 0;
	specs_t specs[] = {
		{'c', store_char},
		{'s', store_string},
		{0, NULL}
	};

	for (i = 0; specs[i].spec; i++)
	{
		if (data->fmt_spec == specs[i].spec)
		{
			tmp = specs[i].func(list, data);
			if (tmp)
			{
				while (j < tmp->len)
					pf_buf_t_add_char(buffer, tmp->buf[j++]);
				len = tmp->len;
				pf_buf_t_delete(tmp);
			}
		}
	}
	return (len);
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
	int i = 0, len = 0, status = OK;
	spec_data_t *data = NULL;
	pf_buf_t *buffer;
	int total_len = 0;

	buffer = pf_buf_t_new(BUFSIZE);
	if (!buffer)
		return (0);

	va_start(list, format);

	if (!format)
		return (-1);

	len = _strlen((char *)format);
	while (format[i] && i < len)
	{
		while (format[i] && format[i] != '%')
		{
			pf_buf_t_add_char(buffer, format[i++]);
			total_len++;
		}

		if (format[i] == '%')
		{
			data = spec_data_t_new();
			if (data)
			{
				status = spec_data_t_parse(data, format + i);
				if (status == OK)
				{
					if (data->fmt_spec == '%')
					{
						pf_buf_t_add_char(buffer, '%');
						i++;
						total_len++;
					}
					else
					{
						total_len += spec_eng(list, data, buffer);
						i += data->fmt_len;
					}
				}
				else if (status == EMPTY)
				{
						pf_buf_t_add_char(buffer, '%');
						total_len++;
				}
				else
				{
					return (-1);
				}
				spec_data_t_delete(data);
			}
			else
			{
				return (-1);
			}
		}
		i++;
	}
	pf_buf_t_print(buffer);
	va_end(list);
	pf_buf_t_delete(buffer);
	return (total_len);
}
