#include "holberton.h"

/**
 * store_char - returns a single char to buffer
 *
 * @c: a char
 *
 * Return: a string
 */

char *store_char(va_list c)
{
	char *ch = va_arg(c, int);
	
	return (ch);
}

/**
 * store_string- returns a string to buffer
 *
 * @s: a string
 *
 * Return: a string
 */

char *store_string(va_list str)
{
	char *arg = va_arg(str, char*);

	if (arg == NULL)
		arg = "(null)";

	return (arg);
}
