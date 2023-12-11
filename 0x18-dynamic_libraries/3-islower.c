#include "main.h"
/**
 * _islower - checks for lowercase
 * @c: c is char
 * Return: 1 if success
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
