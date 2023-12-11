#include <unistd.h>
/**
 * _putchar - prints char
 * @c: char
 * Return: 0 if success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
