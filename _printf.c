#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * print_char - print character to stdout
 * @args: arguments to be passed
 *
 * Return: character
 */
int print_char(va_list args)
{
	int c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - print a string to stdout
 * @args: arguments to be passed
 *
 * Return: string
 */
int print_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	while (*str)
	{
		count += write(1, str++, 1);
	}
	return (count);
}
/**
 * print_percent - print the percent sign
 * @args: arguments to be passed
 *
 * Return: percent sign
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * print_custom_r - print custom character
 *@args: arguments
 *
 * Return: arguments
 */

int print_custom_r(va_list args)
{
	(void)args;
	return (write(1, "%r", 2));
}

const ConvSpecifierInfo convHandlers[] =

{
	{'c', &print_char},
	{'s', &print_string},
	{'%', &print_percent},
	{'r', &print_custom_r}
};
/**
 * _printf - print to stdout
 * @format: pointer to a constant character
 * ...: variable arguments
 *
 * Return: arguments
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; i < sizeof(convHandlers) / sizeof(convHandlers[0]); i++)
			{
				if (*format == convHandlers[i].specifier)
				{
					count += convHandlers[i].handler(args);
					break;
				}
			}
			if (i == sizeof(convHandlers) / sizeof(convHandlers[0]))
			{

			}
		} else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (count);
}
