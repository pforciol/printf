#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

/**
 * struct spec_data - specifiers data
 *
 * @flags: - +   0 ' #
 * @width: minimum number of characters to output
 * @prec: maximum limit on the output, depending on the type
 * @length: hh h l ll L z j t
 * @spec: % d,i u f,F e,E g,G x,X o s,S c p a,A n b r,R
 */

typedef struct spec_data
{
	char *flags;
	char *width;
	char *prec;
	char *length;
	char spec;
	int len;
} spec_data_t;

/**
 * struct pf_buf - _printf buffer
 *
 * @buf: the buffer
 * @len: the size to print of the buffer
 */

typedef struct pf_buf
{
	char *buf;
	int len;
	int index;
} pf_buf_t;

/**
 * struct specs - specifiers structure containing associated funcions
 *
 * @spec: the specifier
 * @func: the print function associated to the specifier
 */

typedef struct specs
{
	char spec;
	pf_buf_t *(*func)(va_list, spec_data_t*);
} specs_t;


/* UTILS */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strcat(char *s1, char *s2);
char *_charcat(char *str, char c);
char *_strdup(char *str);
int _isalpha(int c);
int _islower(int c);
int _isdigit(int c);
int _strnchr(char *s, char c, unsigned int n);
void rev_string(char *str);
char *_strcpy(char *dest, char *src);

/* PRINTF */
int _printf(const char *format, ...);
int spec_eng(va_list list, spec_data_t *data, pf_buf_t *buffer);
pf_buf_t *store_char(va_list c, spec_data_t *data);
pf_buf_t *store_string(va_list str, spec_data_t *data);
spec_data_t *parse_spec(const char *format);
spec_data_t *new_spec_data(
		char spec, char *length, char *prec, char *width, char *flags, int len);
void *free_spec_data(spec_data_t *data);

/* PF_BUF_T */
pf_buf_t *pf_buf_t_new(size_t size);
void *pf_buf_t_delete(pf_buf_t *buffer);
void pf_buf_t_add_char(pf_buf_t *buffer, char to_add);
void pf_buf_t_flush(pf_buf_t *buffer);
void pf_buf_t_print(pf_buf_t *buffer);

#endif
