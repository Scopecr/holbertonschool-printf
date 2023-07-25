#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - length of a string
 * @str: pointer
 *
 * Return: length of the string
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
 * _itoa - convert an integer to a string
 * @num: number
 *
 * Return: the string representation of the number
 */
char *_itoa(int num)
{
	int count = 0;
	int temp = num;
	int i;

	char *str = (char *)malloc((count + 1) * sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}

	while (temp != 0)
	{
		temp /= 10;
		count++;
	}

	for (i = count - 1; i >= 0; i--)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	str[count] = '\0';
	return (str);
}

/**
 * _write_char - write a character to stdout
 * @c: the character to write
 *
 * Return: number of characters written (1 in this case)
 */
int _write_char(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _write_str - write a string to stdout
 * @str: pointer to the string to write
 *
 * Return: number of characters written (excluding the null byte)
 */
int _write_str(char *str)
{
	int len = _strlen(str);
	return (write(STDOUT_FILENO, str, len));
}

/**
 * _printf - print output to stdout according to a format
 * @format: pointer to the format string
 *
 * Return: the number of characters printed (excluding the null byte)
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

			switch (format[i])
			{
				case 'c':
					{
						char c = va_arg(args, int);
						printed_chars += _write_char(c);
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char*);
						printed_chars += _write_str(str);
						break;
					}
				case '%':
					{
						printed_chars += _write_char('%');
						break;
					}
				default:
					{
						printed_chars += _write_char('%');
						printed_chars += _write_char(format[i]);
						break;
					}
			}
		}
	}

	va_end(args);

	return (printed_chars);
}

