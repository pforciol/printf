#include "holberton.h"

/**
 * store_int - returns a temp buffer containing an int in string form
 *
 * @list: the va_list containing the element to print
 * @data: the struct containing the specifier metadata
 *
 * Return: a pointer to a temp pf_buf_t struct
 */

pf_buf_t *store_int(va_list list, spec_data_t *data)
{
	int num = va_arg(list, int);
	pf_buf_t *tmp = NULL;
	int length;
	char *str;
	(void)data;

	str = _itoa(num);

	if (str == NULL)
		str = "(null)";

	length = _strlen(str);
	if (length)
	{
		tmp = pf_buf_t_new(length);
		if (tmp)
			_strcpy(tmp->buf, str);
	}
	
	free(str);
	return (tmp);
}
