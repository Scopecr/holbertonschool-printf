#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_int - print an integer value
 * @args: arguments
 *
 * Return: len
 */
int print_int(va_list args)
{
	(void) args;
	int num_str[12];
	int num = va_list(args, int);
	int len = 0;
	int i;

	if (num == 0)
	{
		return _putchar('0');
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	while (num != 0)
	{
		num_str[len++] = num % 10 + '0';
		num /= 10;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
	}
	return (len);
}
