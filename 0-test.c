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

	printf("1) Simple sentence\n");
	ret = printf("Let's try to printf a simple sentence (just format).\n");
	printf("> RET = %d\n", ret);
	ret = _printf("Let's try to printf a simple sentence (just format).\n");
	printf("> RET = %d\n\n", ret);
	printf("----------\n");

	printf("2) s format, string\n");
	ret = printf("%s", "Let's try to printf a simple sentence.\n");
	printf("> RET = %d\n", ret);
	ret = _printf("%s", "Let's try to printf a simple sentence.\n");
	printf("> RET = %d\n\n", ret);
	printf("----------\n");

	printf("3) c format, NULL value\n");
	ret = printf("%c", NULL);
	printf("\n> RET = %d\n", ret);
	ret = _printf("%c", NULL);
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("4) c format, \\0 value\n");
	ret = printf("%c", '\0');
	printf("\n> RET = %d\n", ret);
	ret = _printf("%c", '\0');
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("5) c format, H value\n");
	ret = printf("%c", 'H');
	printf("\n> RET = %d\n", ret);
	ret = _printf("%c", 'H');
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("6) s format\\0s format, \"Hello\", \"World\"\n");
	ret = printf("%s\0%s", "Hello", " World");
	printf("\n> RET = %d\n", ret);
	ret = _printf("%s\0%s", "Hello", " World");
	printf("\n> RET = %d\n", ret);
	printf("----------\n");
	
	printf("7) c format, 50\n");
	ret = printf("%c", 50);
	printf("\n> RET = %d\n", ret);
	ret = _printf("%c", 50);
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("8) s format, NULL string\n");
	ret = printf("%s", NULL);
	printf("\n> RET = %d\n", ret);
	ret = _printf("%s", NULL);
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("9) s format, empty string\n");
	ret = printf("%s", "");
	printf("\n> RET = %d\n", ret);
	ret = _printf("%s", "");
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("10) s format, \\0 string\n");
	ret = printf("%s", "\0");
	printf("\n> RET = %d\n", ret);
	ret = _printf("%s", "\0");
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("11) s format, space string\n");
	ret = printf("%s", " ");
	printf("\n> RET = %d\n", ret);
	ret = _printf("%s", " ");
	printf("\n> RET = %d\n", ret);
	printf("----------\n");

	printf("s format c format, string, H\n");
	ret = printf("%s%c", "Test String and this is a char: ", 'H');
	printf("\n> RET = %d\n", ret);
	ret = _printf("%s%c", "Test String and this is a char: ", 'H');
	printf("\n> RET = %d\n", ret);
	return(0);
}
