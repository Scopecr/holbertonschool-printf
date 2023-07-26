#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"


struct ConvSpecifierInfo
{
    char specifier;
    convHandler handler;
};


const ConvSpecifierInfo convHandlers[] =
{
    {'c', &print_char},
    {'s', &print_string},
    {'%', &print_percent},
    {'r', &print_custom_r}
};
