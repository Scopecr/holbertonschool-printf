#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

const ConvSpecifierInfo convHandlers[] =
{
  {'c', &print_char},
  {'s', &print_string},
  {'%', &print_percent},
  {'r', print_anything}
};

int print_char(va_list args)
{
    int c = va_arg(args, int);
    return write(1, &c, 1);
}

int print_string(va_list args)
{
    const char *str = va_arg(args, const char *);
    int count = 0;
    while (*str)
    {
        count += write(1, str++, 1);
    }
    return count;
}

int print_percent(va_list args)
{
    (void)args;
    return write(1, "%", 1);
}

int print_anything(va_list args)
{
    int count = 0;
    const char *format = va_arg(args, const char *);

    count += write(1, "%", 1);

    if (*format == '%')
    {
        count += write(1, format, 1);
    }

    return count;
}
