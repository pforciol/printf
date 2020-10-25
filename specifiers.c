#include "holberton.h"

char *extract_format(const char *format, int size)
{
	char *str = "";

	if (size > 1)
	{
		str = malloc(sizeof(char) * size);
		if (str)
			_strncpy(str, (char *)(format + 1), size - 1);
	}

	return (str);
}

char *extract_length(char *str)
{
	int str_length = _strlen(str);
	int i = str_length - 1, j;
	char *str_result = "";
	char *length_specifiers[LENGTH_SPECS_SIZE] = {
		"hh", "h", "l", "ll", "L", "z", "j", "t" };

	if (_isalpha(str[i]) && str_length > 0)
	{
		while (i > 0 && _isalpha(str[i - 1]))
			i--;
		for (j = 0; j < LENGTH_SPECS_SIZE; j++)
		{
			if (_strcmp(str + i, length_specifiers[j]) == 0)
			{
				str_result = malloc(sizeof(char) * (_strlen(str + i) + 1));
				str[i] = '\0';
				break ;
			}
		}
	}
	return (str_result);
}

int extract_prec(char *str)
{
	int str_length = _strlen(str);
	int i;

	i = _strnchr(str, '.', str_length);
	if (i)
}
