#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "main.h"

/**
 * read_textfile - function that reads
 * a text file and prints
 * it to the POSIX standard output
 * @filename: pointeur to the file
 * @letters: number of letters to read and print
 *
 * Return: number of letters to read and print
 * or 0 if filename is NULL
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
