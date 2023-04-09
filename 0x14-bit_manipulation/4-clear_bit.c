#include "main.h"
/**
 * clear_bit - Entry Point
 * @n: input
 * @index: index
 * Return: 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index >= 64)
		return (-1);
	*n = *n & ~(1 << index);
	return (1);
}
