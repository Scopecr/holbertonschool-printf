#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Mainly putting stuff in correct order */

/**
 * struct specifierInfo - Struct specifierInfo
 *
 * @specifier: character specifier
 * @handler: pointer to array handler
 */
typedef struct specifierInfo
{
char *specifier;
int (*handler)(va_list args);
} spec_dt;

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

int printVariables(const char *format, int c, va_list args);
int lenghtvariable(const char *format, int c, va_list args);
#endif
