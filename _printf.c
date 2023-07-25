#include <stdarg.h>
#include <unistd.h>

/**
 * _strlen - Calculate the length of a string.
 * @str: Pointer to the string.
 *
 * Return: Length of the string.
 */
int _strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    return (len);
}

/**
 * _write_char - Write a character to stdout.
 * @c: The character to write.
 *
 * Return: Number of characters written (1 in this case).
 */
int _write_char(char c)
{
    return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _write_str - Write a string to stdout.
 * @str: Pointer to the string to write.
 *
 * Return: Number of characters written (excluding the null byte).
 */
int _write_str(char *str)
{
    int len = _strlen(str);
    return (write(STDOUT_FILENO, str, len));
}

/**
 * _printf - Print output to stdout according to a format.
 * @format: Pointer to the format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    int i;

    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            printed_chars += _write_char(format[i]);
        }
        else
        {
            i++;

            if (format[i] == '\0')
                break;

            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                printed_chars += _write_char(c);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char*);
                printed_chars += _write_str(str);
            }
            else if (format[i] == '%')
            {
                printed_chars += _write_char('%');
            }
            else
            {
                printed_chars += _write_char('%');
                printed_chars += _write_char(format[i]);
            }
        }
    }

    va_end(args);

    return (printed_chars);
}
