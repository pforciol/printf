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
