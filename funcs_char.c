#include "holberton.h"

/**
 * store_char - returns a temp buffer containing the string
 *
 * @list: the va_list containing the element to print
 * @data: the struct containing the specifier metadata
 *
 * Return: a pointer to a temp pf_buf_t struct
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
 * store_string - returns a temp buffer containing the string
 *
 * @list: the va_list containing the element to print
 * @data: the struct containing the specifier metadata
 *
 * Return: a pointer to a temp pf_buf_t struct
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

/**
 * store_rev - returns a temp buffer containing the reversed string
 *
 * @list: the va_list containing the element to print
 * @data: the struct containing the specifier metadata
 *
 * Return: a pointer to a temp pf_buf_t struct
 */

pf_buf_t *store_rev(va_list list, spec_data_t *data)
{
	char *str = va_arg(list, char*);
	char *str2;
	pf_buf_t *tmp = NULL;
	int length;
	(void)data;

	if (str == NULL)
		str = "(null)";
	else
	{
		str2 = _strdup(str);
		rev_string(str2);
	}

	length = _strlen(str2);
	if (length)
	{
		tmp = pf_buf_t_new(length);
		if (tmp)
			_strcpy(tmp->buf, str2);
	}

	free(str2);

	return (tmp);
}

/**
 * store_rot13 - returns a temp buffer containing the ROT13'd string
 *
 * @list: the va_list containing the element to print
 * @data: the struct containing the specifier metadata
 *
 * Return: a pointer to a temp pf_buf_t struct
 */

pf_buf_t *store_rot13(va_list list, spec_data_t *data)
{
	char *str = va_arg(list, char*);
	char *cpy;
	pf_buf_t *tmp = NULL;
	int length, i, j;
	char *src = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *dst = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	(void)data;

	if (str == NULL)
		str = "(null)";
	else
	{
		cpy = _strdup(str);
		for (i = 0; cpy[i]; i++)
		{
			for (j = 0; src[j]; j++)
			{
				if (cpy[i] == src[j])
				{
					cpy[i] = dst[j];
					break;
				}
			}
		}
	}

	length = _strlen(cpy);

	if (length)
	{
		tmp = pf_buf_t_new(length);
		if (tmp)
			_strcpy(tmp->buf, cpy);
	}

	free(cpy);

	return (tmp);
}

pf_buf_t *store_strnop(va_list list, spec_data_t *data)
{
	pf_buf_t *tmp = NULL;
	(void)list;
	(void)data;

	return (tmp);
}
