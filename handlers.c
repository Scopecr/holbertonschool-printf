#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

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

int print_custom_r(va_list args)
{
    (void)args;
    return write(1, "%r", 2);
}
