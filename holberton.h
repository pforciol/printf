#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024
#define SPECIFIERS_SIZE 23
#define LENGTH_SPECS_SIZE 8

#define ERROR -1
#define EMPTY 0
#define OK 1

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
	char fmt_spec;
	char *spec_length;
	int spec_prec;
	int spec_width;
	char *spec_flags;
	int fmt_len;
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
char *_strncpy(char *dest, char *src, int size);
int _strcmp(char *s1, char *s2);

/* PRINTF */
int _printf(const char *format, ...);
int spec_eng(va_list list, spec_data_t *data, pf_buf_t *buffer);
int is_in_format_specifiers(char c);

pf_buf_t *store_char(va_list c, spec_data_t *data);
pf_buf_t *store_string(va_list str, spec_data_t *data);

/* SPEC_DATA_T */
int spec_data_t_parse(spec_data_t *data, const char *format);
spec_data_t *spec_data_t_new(void);
void *spec_data_t_delete(spec_data_t *data);

/* PF_BUF_T */
pf_buf_t *pf_buf_t_new(size_t size);
void *pf_buf_t_delete(pf_buf_t *buffer);
void pf_buf_t_add_char(pf_buf_t *buffer, char to_add);
void pf_buf_t_flush(pf_buf_t *buffer);
void pf_buf_t_print(pf_buf_t *buffer);

/* SPECIFIERS */
char *extract_format(const char *format, int size);
char *extract_length(char *str);

#endif
