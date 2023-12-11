#include "main.h"
#include <stdio.h>
/**
 * _strpbrk - a function that searches a string for any of a set of bytes.
 * @s: ptr to char
 * @accept: char
 * Return: null
 */
char *_strpbrk(char *s, char *accept)
{
	int j;

	while (*s)
	{
		for (j = 0; accept[j]; j++)
		{
			if (*s == accept[j])
			{
				return (s);
			}
		}
		s++;
	}
	return (NULL);
}
