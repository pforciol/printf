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
	char *str = NULL;
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

	return (str);
}

/**
 * _chartohex - converts ascii value to hex and stores in string
 *
 * @ch: the ascii value to convert
 *
 * Return: a string containing the number in hexadecimal
 */

char *_chartohex(int ch)
{
	unsigned long quo, rem;
	int j = 0;
	char res[2] = "00";
	char *ret;

	quo = ch;

	while (quo != 0)
	{
		rem = quo % 16;
		if (rem < 10)
			res[j++] = 48 + rem;
		else
			res[j++] = 55 + rem;
		quo /= 16;
	}
	if (!res[1])
		res[1] = '0';
	res[2] = '\0';
	rev_string(res);

	ret = _strdup(res);
	
	return (ret);
}
