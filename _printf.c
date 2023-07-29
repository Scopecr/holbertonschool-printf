#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - formatted output to stdout
 * @format: pointer to a constant character
 * ...: variable argument
 *
 * Return: count
 */


int _printf(const char *format, ...)
{
	
	int count = 0, c = 0;
	va_list args;

	va_start(args, format);

	count += lenghtvariable(format, c, args);
	va_end(args);
	return (count);
}

/**
 * lenghtvariable - counts any lettr that isnt a variable
 * @format: pointer to a constant character
 * @args: list of arguments
 * @c: current letter of format we are in
 *
 * Return: count
 */


int lenghtvariable(const char *format, int c, va_list args)
{
	int count;

	
	if (format == NULL)
	{
		
		return (-1);
	}

	while (format[c])
	{
		if (format[c] == '%')
		{
			if (format[c + 1] == '\0')
			{
				return (-1);
			}
			c++;

			count += printVariables(format, c, args);
		}
		else
		{
			_putchar(format[c]);
			count++;
		}

		c++;
	}

	return (count);
}

/**
 * printVariables - prints the variables
 * @format: pointer to a constant character
 * @args: list of arguments
 * @c: current letter of format we are in
 *
 * Return: count
 */

int printVariables(const char *format, int c, va_list args)
{
	int count = 0, i, valid = 0;

	
	spec_dt handlers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_i},
		{"d", print_d},
		{NULL, NULL}
	};


	for (i = 0; i < 5; i++)
	{
		if (format[c] == *handlers[i].specifier)
		{
			valid = 1;
			count += handlers[i].handler(args);
		}
	}

	if (valid == 0)
	{
		count += _putchar('%');
		count += _putchar(format[c]);
	}

	return (count);
}