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

char *extract_length(char *str, spec_data_t *data)
{
	int str_length = _strlen(str);
	int i = str_length - 1, j;
	char *str_result = "";
	char *length_specifiers[LENGTH_SPECS_SIZE] = {
		"hh", "h", "l", "ll", "L", "z", "j", "t" };

	data->status = EMPTY;

	if (_isalpha(str[i]) && str_length > 0)
	{
		while (i > 0 && _isalpha(str[i - 1]))
			i--;
		for (j = 0; j < LENGTH_SPECS_SIZE; j++)
		{
			if (_strcmp(str + i, length_specifiers[j]) == 0)
			{
				str_result = malloc(sizeof(char) * (_strlen(str + i) + 1));
				if (str_result)
					_strncpy(str_result, length_specifiers[j], 2);
				str[i] = '\0';
				data->status = (str_result) ? OK : ERROR;
				break ;
			}
		}
		data->status = INVALID;
	}
	return (str_result);
}

int extract_prec(char *str, spec_data_t *data)
{
	int str_length = _strlen(str);
	int i = 0, j = 0, prec = -1;

	data->status = EMPTY;

	i = _strnchr(str, '.', str_length);
	if (str_length > 0 && i != -1 )
	{
		j = i + 1;
		while (str[j] && _isdigit(str[j]))
			j++;
		if (j != str_length)
		{
			data->status = INVALID;
		}
		else
		{
			prec = _atoi(str + i + 1);
			str[i] = '\0';
			data->status = OK;
		}
	}
	return (prec);
}

int extract_width(char *str, spec_data_t *data)
{
	int str_length = _strlen(str);
	int i = str_length - 1, width = 0;

	data->status = EMPTY;

	if (_isdigit(str[i]) && str_length > 0)
	{
		while (i > 0 && _isdigit(str[i - 1]))
			i--;
		if (str[i] == '0')
			i++;
		width = _atoi(str + i);
		str[i] = '\0';
		data->status = OK;
	}
	return (width);
}

char *extract_flags(char *str, spec_data_t *data)
{
	int str_length = _strlen(str), i = 0;
	char *str_result = "";
	char flags_specifiers[FLAGS_SPECS_SIZE] = "-+ 0'#";
	
	data->status = EMPTY;

	if (str_length > 0)
	{
		while (str[i])
		{
			if (_strchr(flags_specifiers, str[i]) == NULL)
				break ;
			i++;
		}
		if (i == str_length)
		{
			str_result = malloc(sizeof(char) * str_length + 1);
			if (str_result)
				_strncpy(str_result, str, str_length);
			data->status = (str_result) ? OK : ERROR;
		}
		else
		{
			data->status = INVALID;
		}
	}
	return (str_result);
}
