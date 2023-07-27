README.md

Group Project

C library function printf, for printing formatted output to stdout.
printf is part of standard library #include <stdio.h>

Syntax:
printf("format String/format specifier", Arguments);

Example:
int y = 10;

printf("the number to be printed is: %i", y);

char c = 't';

printf("print the following character: %c", c);

Specifiers:
"" start and end of the string to be printed
format string: is a string that specifies the output
format specifier: to print the value of any variable such as a character and an integer value

Format Specifiers:
%c print a single character
%d print a decimal number
%e print an exponential floating-point number
%g print a general-format floating-point number
%i print an integer number
%o print a number in octal
%s print a string
%u print an unsigned decimal number
%x print a number in hexidecimal
%% print a percent sign (or: \%)


Flags and Description:
(-) left justify (right justification is the default)
(+) forces the result with a plus or minus sign (+ or -)
(space) if no sign is to be written, a blank space is inserted before the value
0 leading zero fill
