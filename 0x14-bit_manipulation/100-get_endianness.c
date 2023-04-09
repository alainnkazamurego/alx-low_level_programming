#include "main.h"
/**
 * get_endianness - return endianness
 * Return: 0
 */
int get_endianness(void)
{
	int n = 1;

	return (*((char *) &n) + '0');
}
