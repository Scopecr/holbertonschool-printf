#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct specifierInfo specifierInfo;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_anything(va_list args);
int print_i(va_list args);
int print_d(va_list args);
int print_bi(unsigned int n);
int print_hexalow(unsigned int n);

/**
 * struct ConvSpecifierInfo - Struct ConvSpecifierInfo
 *
 * @specifier: character specifier
 * @handler: pointer to array handler
 */
struct specifierInfo
{
char specifier;
int (*handler)(va_list args);
};

#endif
