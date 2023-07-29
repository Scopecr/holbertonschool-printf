#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"


/**
 * print_char - print a character
 * @args: arguments
 *
 * Return: printed arguments
 */
int print_char(va_list args)
{

	int c = va_arg(args, int);


	_putchar(c);
	return (1);
}

/**
 * print_string - print a string
 * @args: arguments
 *
 * Return: string
 */
int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;


	if (str != NULL)
	{
		while (str[count])
		{
			_putchar(str[count]);
			count++;
		}

		return (count);
	}

	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');
	return (6);
}
/**
 * print_percent - print a percent sign
 * @args: arguments
 *
 * Return: Percent sign
 */
int print_percent(va_list args)
{

	(void)args;
	return (write(1, "%", 1));
	return (1);
}

/**
 * print_int_i - print a unsigned integer.
 * @args: Parameters.
 *
 * Return: Count.
 */

int print_int_i(va_list args)
{
	int count = 0;
	char num_str[12];
	int len = 0, i, num = va_arg(args, int);

	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		while (num != 0)
		{
			num_str[len++] = num % 10 + '0';
			num /= 10;
		}

		for (i = len - 1; i >= 0; i--)
		{
			write(1, &num_str[i], 1);
			count++;
		}
	}

	return (count);
}

/**
 * print_int_d - print a signed integer.
 * @args: parameters.
 *
 * Return: Count.
 */

int print_int_d(va_list args)
{
	int count = 0;
	char num_str[12];
	int len = 0, i, num = va_arg(args, int);

	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}

	while (num != 0)
	{
		num_str[len++] = num % 10 + '0';
		num /= 10;
	}

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &num_str[i], 1);
		count++;
	}

	return (count);
}

