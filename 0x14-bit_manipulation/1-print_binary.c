#include <stdio.h>
#include "main.h"

/**
 * print_binary - print an unsigned int - Entry Point
 * @n: input
 * Return: 0
 */
void print_binary(unsigned long int n)
{

	unsigned long int prbi = 1ul << 63;
	char c = '0';

	while (!(prbi & n) && prbi != 0)
		prbi = prbi >> 1;
	if (prbi == 0)
		write(1, &c, 1);
	while (prbi)
	{
		if (prbi & n)
			c = '1';
		else
			c = '0';
		write(1, &c, 1);
		prbit = prbi >> 1;
	}
}
