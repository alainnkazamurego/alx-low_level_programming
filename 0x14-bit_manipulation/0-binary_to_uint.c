#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Entry Point
 * @b: const char
 * Return: 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int sol = 0;
	int be = 1, i = 0;

	if (b == NULL)
		return (0);

	while (b[i + 1])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		i++;
	}

	while (i >= 0)
	{
		sol += ((b[i] - '0') * be);
		be *= 2;
		i--;
	}


	return (sol);

}
