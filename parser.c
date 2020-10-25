#include "holberton.h"

void *free_spec_data(spec_data_t *data)
{
	if (data)
	{
		if (data->length)
			free(data->length);
		if (data->prec)
			free(data->prec);
		if (data->width)
			free(data->width);
		if (data->flags)
			free(data->flags);
		free(data);
	}
	return (NULL);
}

spec_data_t *new_spec_data(
		char spec, char *length, char *prec, char *width, char *flags, int len)
{
	spec_data_t *new;

	new = malloc(sizeof(spec_data_t));
	if (!new)
		return (NULL);
	new->spec = spec;
	new->len = len;

	new->length = _strdup(length);
	if (!new->length)
		return (free_spec_data(new));

	rev_string(prec);
	new->prec = _strdup(prec);
	if (!new->prec)
		return (free_spec_data(new));

	rev_string(width);
	new->width = _strdup(width);
	if (!new->width)
		return (free_spec_data(new));

	rev_string(flags);
	new->flags = _strdup(flags);
	if (!new->flags)
		return (free_spec_data(new));

	return (new);
}

spec_data_t	*parse_spec(const char *format)
{
	char spec, length[100], prec[100], width[100], flags[100];
	int i = 1, j = 0, len = 0;

	char specs[24] = "diufFeEgGxXosScpaAnbrR%";

	while (format[i] && format[i] != ' ')
	{
		j = _strnchr(specs, format[i], 24);
		if (j != -1)
			break;
		i++;
	}

	spec = specs[j];
	len = (j == -1) ? 0 : i;
	i = len - 1;

	if (j != -1)
	{
		j = 0;
		while (i > 0 && format[i] && _isalpha(format[i]) == 1)
		{
			length[j++] = format[i--];
		}
		length[j] = '\0';

		j = 0;
		if (_strnchr((char *)format, '.', len) != -1)
		{
			while (i > 0 && format[i] && format[i] != '.')
			{
				prec[j++] = format[i--];
			}
			i--;
		}
		prec[j] = '\0';

		j = 0;
		while (i > 0 && format[i] && _isdigit(format[i]) && format[i] != '0')
			width[j++] = format[i--];
		width[j] = '\0';

		if (j > 0 && width[j - 1] == '0')
		{
			flags[0] = '0';
			width[j - 1] = '\0';
			j = 1;
		}
		else 
		{
			j = 0;
		}

		while (i > 0 && format[i])
			flags[j++] = format[i--];
		flags[j] = '\0';
	}

	return (new_spec_data(spec, length, prec, width, flags, len));
}
