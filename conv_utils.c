#include "holberton.h"

/**
 * _atoi - converts a number in a string to an int
 *
 * @s: string containing the number to convert
 *
 * Return: an int
 */


int	_atoi(char *s)
{
	int i = 0, sign = 0, res = 0;

	while (s[i] && (!(s[i] >= '0') || !(s[i] <= '9')))
	{
		if (s[i] == '-')
			sign++;
		i++;
	}
	sign = (sign % 2) ? -1 : 1;
	while (s[i] && ((s[i] >= '0') && (s[i] <= '9')))
		res = res * 10 + (s[i++] - '0') * sign;
	return (res);
}

/**
 * _itoa - converts an int to an ascii string
 *
 * @i: int to convert
 *
 * Return: a string containing the number in ascii chars
 */

char *_itoa(int i)
{
	char *str, *res;
	unsigned int n = i;
	int j = 0;

	str = malloc(sizeof(char) * 11);
	if (!str)
	{
		free(str);
		return (NULL);
	}

	if (i < 0)
		n = -i;

	while (n / 10)
	{
		str[j++] = (n % 10) + '0';
		n /= 10;
	}

	str[j++] = (n % 10) + '0';

	if (i < 0)
		str[j++] = '-';

	str[j] = '\0';
	rev_string(str);

	res = _strdup(str);
	free(str);

	return (res);
}
