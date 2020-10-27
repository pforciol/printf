#include "holberton.h"

/**
 * _uitoa - converts an unsigned int to an ascii string
 *
 * @i: int to convert
 *
 * Return: a string containing the number in ascii chars
 */

char *_uitoa(unsigned int i)
{
	char *str = NULL;
	unsigned int n = i;
	int j = 0;

	str = malloc(sizeof(char) * 11);
	if (!str)
	{
		free(str);
		return (NULL);
	}

	while (n / 10)
	{
		str[j++] = (n % 10) + '0';
		n /= 10;
	}
	str[j++] = (n % 10) + '0';
	str[j] = '\0';

	rev_string(str);

	return (str);
}

/**
 * _ptrtohex - converts pointer address to hex and stores in string
 *
 * @uint: the unsigned int to convert
 * @upper: case flag (returns uppercase hex if 1, lowercase hex if 0)
 *
 * Return: a string containing the number in hexadecimal
 */

char *_ptrtohex(unsigned long ptr)
{
	unsigned long quo, rem;
	int j = 0;
	char res[10] = "";
	char *ret;

	quo = ptr;
	while (quo != 0)
	{
		rem = quo % 16;
		if (rem < 10)
			res[j++] = 48 + rem;
		else
		{
			res[j++] = 87 + rem;
		}
		quo /= 16;
	}

	if (ptr == 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else
		res[j++] = 'x';
		res[j++] = '0';
		res[j++] = '\0';
	rev_string(res);

	ret = _strdup(res);

	return (ret);
}
