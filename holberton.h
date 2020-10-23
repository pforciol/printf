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
	char *spec;
	char *(*func)(va_list);
} specs_t;

/* UTILS */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strcat(char *s1, char *s2);
char *_charcat(char *str, char c);

/* PRINTF */
int _printf(const char *format, ...);
char *store_char(va_list c);
char *store_string(va_list str);

#endif
