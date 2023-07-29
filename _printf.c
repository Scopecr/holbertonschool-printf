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
	unsigned int i;
	
	int count = 0, c = 0, valid = 0;

	
	spec_dt handlers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_i},
		{"d", print_d},
		{NULL, NULL}
	};

	va_list args;

	va_start(args, format);
	
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

			
			for (i = 0; i < 5; i++)
			{
				if (format[c] == *handlers[i].specifier)
				{
					valid = 1;
					/* += looks cleaner */
					count += handlers[i].handler(args);
				}
				
			}
			
			if (valid == 0)
			{
				count += _putchar('%');
				count += _putchar(format[c]);
			}
		}
		
		else
		{
			_putchar(format[c]);
			count++;
		}

		c++;
	}

	va_end(args);
	return (count);
}