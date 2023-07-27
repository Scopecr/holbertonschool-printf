#include "main.h"
#include <stdlib.h>
/**
 * print_hexalow - convert unsigned int in hexadecimal
 * @n: unsigned int
 * Return: numer times print
 */

int print_hexalow(unsigned int n)
{
	int i, j, reminder, count = 0;
	unsigned int num_copy = n;
	char *hexadecimal;

	if (n == 0)
		return (_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		count++;
	}
	hexadecimal = malloc(count);
	for (i = 0; n != 0; i++)
	{
		reminder = n % 16;
		if (reminder < 10)
		{
			hexadecimal[i] = reminder + '0';
		}
		else
		{
			hexadecimal[i] = reminder + 'W';
		}
		n /= 16;
	}
	for (j = i - 1;j >= 0; j --)
		_putchar(hexadecimal[j]);
	free(hexadecimal);
	return (count);
}
