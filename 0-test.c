#include <stdio.h>
#include "holberton.h"

/**
 * main - stress tests for the printf task 0
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int ret = 0;

	ret = printf("%s", "Let's try to printf a simple sentence.\n");
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%s", "Let's try to printf a simple sentence.\n");
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	/* ret = printf("%c", NULL);
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%c", NULL);
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	ret = printf("%c", '\0');
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%c", '\0');
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	ret = printf("%c", 'H');
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%c", 'H');
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	ret = printf("%c", 50);
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%c", 50);
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n"); */ 

	ret = printf("%s", NULL);
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%s", NULL);
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	ret = printf("%s", "");
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%s", "");
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	ret = printf("%s", "\0");
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%s", "\0");
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n");

	ret = printf("%s", " ");
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%s", " ");
	printf("\n\t> RET = %d\n\n", ret);
	printf("----------\n"); /*

	ret = printf("%s%c", "Test String and this is a char: ", 'H');
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("%s%c", "Test String and this is a char: ", 'H');
	printf("\n\t> RET = %d\n\n", ret); */
	return(0);
}
