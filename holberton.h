#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct specs - specifiers structure containing associated funcions
 *
 * @spec: the specifier
 * @func: the print function associated to the specifier
 */

typedef struct specs
{
	char spec;
	char *(*func)(va_list);
} specs_t;

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

/* PRINTF */
int _printf(const char *format, ...);
char *spec_eng(va_list list, spec_data_t *data);
char *store_char(va_list c);
char *store_string(va_list str);
spec_data_t *parse_spec(const char *format);
spec_data_t *new_spec_data(
		char spec, char *length, char *prec, char *width, char *flags, int len);
void *free_spec_data(spec_data_t *data);

#endif
