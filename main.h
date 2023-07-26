#ifndef PRINTF_H
#define PRINTF_H

typedef int (*ConvHandler)(va_list args);

typedef struct
{
	char specifier;
	ConvHandler handler;
} ConvSpecifierInfo;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_custom_r(va_list args);

extern const ConvSpecifierInfo convHandlers[];
#endif
