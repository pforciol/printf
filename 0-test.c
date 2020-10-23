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

	ret = printf("Let's try to printf a simple sentence.\n");
	printf("\n\t> RET = %d\n", ret);
	ret = _printf("Let's try to printf a simple sentence.\n");
	printf("\n\t> RET = %d\n", ret);
	return (0);
}
