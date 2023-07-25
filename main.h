#ifndef PRINTF_H
#define PRINTF_H

int _printf(const char *format, ...);
typedef int (*ConvHandler)(va_list args);

typedef struct
{
	char specifier;
	ConvHandler handler;
} ConvSpecifierInfo;

#endif
