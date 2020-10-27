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

