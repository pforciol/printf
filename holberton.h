#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdarg.h>

/**
 * struct specs - specifiers structure containing associated funcions
 *
 * @spec: the specifier
 * @func: the print function associated to the specifier
 */

typedef struct specs
{
	char *spec;
	void (*func)(va_list);
} specs_t;

int _putchar(char c);
int _printf(const char *format, ...);

#endif
