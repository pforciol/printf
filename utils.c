#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes the string str to stdout
 *
 * @str: The string to print
 */

void _puts(char *str)
{
	int i = 0;
	
	while (str[i])
		_putchar(str[i++]);
}

/**
 * _strlen - returns the length of the string str
 *
 * @str: The string to measure length
 *
 * Return: the length of the str string
 */

int	_strlen(char *str)
{
	int len = 0;

	if (str)
		while (str[len])
			len++;
	return (len);
}

/**
 * _strcat - concatenates two strings
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the new string, or NULL on failure
 */

char *_strcat(char *s1, char *s2)
{
	char *str;
	int i = 0, j = 0;

	str = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	str[i + j] = '\0';
	return (str);
}

/**
 * _charcat - concatenates a char to a string
 *
 * @str: the first string
 * @c: the char
 *
 * Return: a pointer to the new string, or NULL on failure
 */

char *_charcat(char *str, char c)
{
	char *cat;
	int i = 0;

	cat = malloc(sizeof(char) * (_strlen(str) + 2));
	if (!cat)
		return (NULL);
	if (str != NULL)
		while (str[i])
		{
			cat[i] = str[i];
			i++;
		}
	if (c)
		cat[i] = c;
	i++;
	cat[i] = '\0';
	free(str);
	return (cat);
}

/**
 * _isalpha - checks for alphabetic characters
 *
 * @c: character to test (in int)
 *
 * Return: 1 if c is alphabetic, 0 if no
 */

int	_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}

/**
 * _islower - checks for lowercase characters
 *
 * @c: character to test (in int)
 *
 * Return: 1 if c is lowercase, 0 if no
 */

int _islower(int c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

/**
 * _strnchr - locates a character in a string
 *
 * @s: the string to look inside
 * @c: the character to find
 * @n: the max length to look for
 *
 * Return: the index of the first occurence of c in s, or -1 if not found
 */

int _strnchr(char *s, char c, unsigned int n)
{
	unsigned int i = 0;

	while (s[i] && i <= n)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

/**
 * _isdigit - checks for digits
 *
 * @c: character to test (in int)
 *
 * Return: 1 if c is a digit, 0 if no
 */

int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

/**
 * rev_string - reverses a string
 *
 * @s: the string to be reversed
 */

void rev_string(char *str)
{
	int i = 0			;
	int j = _strlen(str) - 1, max = j / 2;
	char tmp;

	while (j > max)
	{
		tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
}

/**
 * _strdup - allocates a new space in memory which contains
 * a copy of the string given as a parameter
 *
 * @str: the string to duplicate
 *
 * Return: a pointer to the new string, or NULL if str = NULL or fail
 */

char *_strdup(char *str)
{
	char *new_str;
	int i = 0;

	if (str == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * _strlen(str) + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
