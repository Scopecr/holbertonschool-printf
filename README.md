# _printf
<br>

<a align="center">
<img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExN3E1djV1MmJwZjJ0ZzBscmVxaWtlaXIzbWFxM2cyZ2JvdWc4OTV0MiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/GwtfUx2P2HnvByDZdg/giphy.gif", />
</a>

Group project for _printf function.

## Description

C library function printf, for printing formatted output to stdout.
printf is part of standard library #include <stdio.h> and takes format
strings or format specifier to print the formatted output.

## Syntax

printf("format String/format specifier", Arguments);

## Compiler

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

## Specifiers
- "" start and end of the string to be printed`
- format string: is a string that specifies the output
- format specifier: to print the value of any variable such as a character and an integer value

## Format Specifiers

- %c print a single character
- %d print a decimal number
- %e print an exponential floating-point number
- %g print a general-format floating-point number
- %i print an integer number
- %o print a number in octal
- %s print a string
- %u print an unsigned decimal number
- %x print a number in hexidecimal
- %% print a percent sign (or: \%)


## Flags

- - left justify (right justification is the default)
- + forces the result with a plus or minus sign (+ or -)
- (space) if no sign is to be written, a blank space is inserted before the value
- 0 leading zero fill

## Example
```c
#include "main.h"
#include <stdio.h>

int main()
{
    char initial = 'L';
    int age = 68;

    printf("Hello, %c. You are %d years young.", initial, age);
}

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o _print

Output:
Hello, L. You are 68 years young.
```

## Authors

-Walter Carrion <wjrcarrion@gmail.com> <https://www.linkedin.com/in/walter-carrion-3a4b29296/> <https://github.com/Scopecr>

-Nadja Miranda <nadeshda02@hotmail.com> <https://www.linkedin.com/in/nadja-miranda-schnuppe/> <https://github.com/nadeshda18>

