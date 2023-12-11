#include "main.h"
/**
 * _isupper - function
 * @c: integer
 * Return: 0 success
 */
int _isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);

	return (0);
}
