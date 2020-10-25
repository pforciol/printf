#include "holberton.h"

void *spec_data_t_delete(spec_data_t *data)
{
	if (data)
	{
		if (data->spec_length)
			free(data->spec_length);
		if (data->spec_flags)
			free(data->spec_flags);
		free(data);
	}
	return (NULL);
}

spec_data_t *spec_data_t_new(void)
{
	spec_data_t *new = NULL;

	new = malloc(sizeof(spec_data_t));

	if (new)
	{
		new->fmt_spec = '\0';
		new->spec_length = NULL;
		new->spec_prec = 0;
		new->spec_width = 0;
		new->spec_flags = NULL;
		new->fmt_len = 0;
	}

	return (new);
}

int spec_data_t_parse(spec_data_t *data, const char *format)
{
	char *str;
	int i = 1, j = 0, len = 0, status = EMPTY;

	while (format[i])
	{
		j = is_in_format_specifiers(format[i]);
		if (j == -1)
			break;
		i++;
	}

	if (j != -1)
	{
		data->fmt_spec = format[i];
		status = OK;
		str = extract_format(format, i);
		 /* precision_secifier = extract_precision(str);
		 * width_specifier = extract_width(str);
		 * flags_specifier = extract_flags(str);
		 */
		if (str)
		{
			data->fmt_len = i;
			if (_strlen(str) != 0)
			{
				data->spec_length = extract_length(str);
				if (data->spec_length != NULL)
					data->spec_prec = extract_prec(str);
				
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
				status = OK;
			}
		}
		else
		{
			status = ERROR;
		}
	}

	return (status);
}

int is_in_format_specifiers(char c)
{
	char specifiers[SPECIFIERS_SIZE] = "diufFeEgGxXosScpaAnbrR%";
	int i = 0;

	while (i < SPECIFIERS_SIZE)
	{
		if (c == specifiers[i])
			return (i);
		i++;
	}
	return (-1);
}
