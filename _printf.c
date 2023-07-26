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

extern const ConvSpecifierInfo convHandlers[];

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
			for (i = 0; i < 3; i++)
			{
				if (*format == convHandlers[i].specifier)
				{
					count += convHandlers[i].handler(args);
					break;
				}
			}
			
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (count);
}
