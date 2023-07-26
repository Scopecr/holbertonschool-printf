#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef int (*convHandler)(va_list args);


typedef struct ConvSpecifierInfo ConvSpecifierInfo;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_custom_r(va_list args);

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


#endif
