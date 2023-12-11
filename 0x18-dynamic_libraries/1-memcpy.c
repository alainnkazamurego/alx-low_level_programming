#include "main.h"
/**
 * _memcpy - function copies n bytes
 * from memory area src to memory area dest
 * Returns a pointer to dest
 * @dest: ptr to char
 * @src: ptr to char
 * @n: index
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
