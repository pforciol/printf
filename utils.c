#include "holberton.h"

/**
 * _strncpy - copies the string pointed to by src to the buffer pointed
 * to by dest and returns the value pointed to by dest
 *
 * @dest: destination buffer
 * @src: source buffer
 * @size: maximum size to copy
 *
 * Return: pointer to dest
 */

char *_strncpy(char *dest, char *src, int size)
{
	int i = 0;

	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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
 *  * _strchr - locates a character in a string
 *   *
 *    * @s: the string to look inside
 *     * @c: the character to find
 *      *
 *       * Return: a pointer to the first occurence of c in s, or NULL if not
 *       found
 *        */

char	*_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

/**
 *  * _strspn - gets the length of a prefix substring
 *   *
 *    * @s: the string
 *     * @accept: bytes to accept in s
 *      *
 *       * Return: number of bytes in the initial segment of s
 *        * which consist only of bytes from accept
 *         */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;

	while (s[i])
		if (_strchr(accept, s[i]) != NULL)
			i++;
		else
			break;
	return (i);
}
