#include "holberton.h"

pf_buf_t *pf_buf_t_new(size_t size)
{
	pf_buf_t *buffer = NULL;

	if (size > 0)
	{
		buffer = malloc(sizeof(pf_buf_t));
		if (buffer)
		{
			buffer->buf = malloc(sizeof(char) * (size + 1));
			if (!buffer->buf)
				return (pf_buf_t_delete(buffer));
			buffer->index = 0;
			buffer->len = size;
		}
	}

	return (buffer);
}

void *pf_buf_t_delete(pf_buf_t *buffer)
{
	if (buffer)
	{
		if (buffer->buf)
			free(buffer->buf);
		free(buffer);
	}
	return (NULL);
}

void pf_buf_t_add_char(pf_buf_t *buffer, char to_add)
{
	if (buffer->index < buffer->len)
	{
		buffer->buf[buffer->index] = to_add;
		buffer->index += 1;
	}
	if (buffer->index == buffer->len)
		pf_buf_t_flush(buffer);
}

void pf_buf_t_flush(pf_buf_t *buffer)
{
	write(1, buffer->buf, buffer->len);
	buffer->index = 0;
}

void pf_buf_t_print(pf_buf_t *buffer)
{
	write(1, buffer->buf, buffer->index);
}
