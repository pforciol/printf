#include "holberton.h"

/**
 * store_char - returns a pointer to pf_but_t
 *
 * @c: a char
 *
 * Return: a pointer to pf_but_t
 */

pf_buf_t *store_char(va_list list, spec_data_t *data)
{
	pf_buf_t *tmp = pf_buf_t_new(1);
	(void)data;

	if (tmp)
		tmp->buf[0] = va_arg(list, int);

	return (tmp);
}

/**
 * store_string- returns a string to buffer
 *
 * @s: a string
 *
 * Return: a string
 */

pf_buf_t *store_string(va_list list, spec_data_t *data)
{
	char *str = va_arg(list, char*);
	pf_buf_t *tmp = NULL;
	int length;
	(void)data;

	if (str == NULL)
		str = "(null)";

	length = _strlen(str);
	if (length)
	{
		tmp = pf_buf_t_new(length);
		if (tmp)
			_strcpy(tmp->buf, str);
	}

	return (tmp);
}
