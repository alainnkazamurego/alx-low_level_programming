#include "main.h"
/**
 * _strchr - function that locates a character in a string.
 * @s: ptr to char
 * @c: char
 * Return: s or 0
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
return (0);
}
