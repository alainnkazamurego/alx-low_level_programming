#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Entry Point
 * @filename: file name
 * @letters: size
 * Return: 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, frd;
	ssize_t result;
	char *buf;

	fd = open(filename, O_RDONLY);

	buf = malloc(sizeof(char) * letters + 1);
	frd = read(fd, buf, letters);
	result = write(1, buf, frd);
	if (filename == NULL || buf == NULL || frd == -1 || result == -1)
	{
		return (0);
	}
	buf[letters] = '\0';
	close(fd);
	free(buf);
	return (result);
}
