#include "main.h"
#include <stdlib.h>

/**
 *print_hexaup - prints numbers in hexadecimal with upper numbers
 *@n: unsigned variable interger
 *Return: number times print
 */

int print_hexaup(unsigned int n)
{
	int i, j, remainder, count = 0;
	unsigned int num_copy = n;
	char *hexadecimal;

	if (n == 0)
		return(_putchar('0'));
	while (num_copy != 0)
	{
		num_copy /= 16;
		count++;
	}
	hexadecimal = malloc(count);
	for (i = 0; n != 0; i++)
	{
		remainder = 0;
		remainder = n % 16;
		if (remainder < 10)
		{
			hexadecimal[i] = remainder + '0';
		}
		else
		{
			hexadecimal[i] = remainder + '7';
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j++)
		_putchar(hexadecimal[j]);
	free(hexadecimal);
	return (count);
}