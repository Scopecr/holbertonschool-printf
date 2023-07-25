#include <stdio.h>
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
 * _itoa - count of string
 * @num: number
 *
 * Return: count
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
 * _printf - print output to stdout
 * @format: pointer
 *
 * Return: string
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
			char c = format[i];

			write(STDOUT_FILENO, &c, 1);
			printed_chars++;
		}

		else
		{
			i++;

			switch (format[i])
			{
				case 'c':
					{
						char c = va_arg(args, int);

						write(STDOUT_FILENO, &c, 1);
						printed_chars++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char*);
						int str_len = _strlen(str);

						write(STDOUT_FILENO, str, str_len);
						printed_chars += str_len;
						break;
					}
				case '%':
					{
						char c = '%';

						write(STDOUT_FILENO, &c, 1);
						printed_chars++;
						break;
					}
				case 'd': case 'i':
					{
						int num = va_arg(args, int);
						char *str = _itoa(num);

						if (str != NULL)
						{
							int str_len = _strlen(str);

							write(STDOUT_FILENO, str, str_len);
							printed_chars += str_len;
							free(str);
						}
						break;
					}
				default:
					{

						char c = '%';

						write(STDOUT_FILENO, &c, 1);
						c = format[i];
						write(STDOUT_FILENO, &c, 1);
						printed_chars += 2;
						break;
					}
			}
		}
	}

	va_end(args);

	return (printed_chars);
}
