#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

const ConvSpecifierInfo convHandlers[] =

{
	{'c', &print_char},
	{'s', &print_string},
	{'%', &print_percent},
	{'r', &print_anything},
	{'i', &print_i},
	{'d', &print_d}
};

/**
 * print_char - print a character
 * @args: arguments
 *
 * Return: printed arguments
 */
int print_char(va_list args)
{
	int count = 0;
	int c = va_arg(args, int);

	count++;
	return (write(1, &c, 1));
	return(count);
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

	while (*str)
	{
		count += write(1, str++, 1);
	}
	count++;
	return (count);
}
/**
 * print_percent - print a percent sign
 * @args: arguments
 *
 * Return: Percent sign
 */
int print_percent(va_list args)
{
	int count = 0;
	(void)args;
	count++;
	return(write(1, "%", 1));
	return(count);
}
/**
 * print_anything - print any character
 * @args: arguments
 *
 * Return: arguments
 */
int print_anything(va_list args)
{
	int count = 0;
	const char *format = va_arg(args, const char *);

	const char c = *format;
	count += write(1, "%", 1);

	format++;
	if (c != '%')
	{
		count += write(1, &c, 1);
	}

	count++;
	return count;
}

/**
 * print_i - print an integer value
 * @args: arguments
 *
 * Return: len
 */
int print_i(va_list args)
{
	int num_str[12];
	int num;
	int len = 0;
	int i;

	num = va_arg(args, int);

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

/**
 * print_d - print decimal numbers
 * @args: arguments
 *
 * Return: len
 */
int print_d(va_list args)
{
	int num_str[12];
    int num;
    int len = 0;
    int i;

	num = va_arg(args, int);

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
    return len;
}
