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
	int fl, rdo, wri;
	char *bf;

	if (filename == NULL)
		return (0);

	fl = open(filename, O_RDONLY);

	if (fl == -1)
		return (0);

	bf = malloc(sizeof(char) * letters + 1);
	if (bf == NULL)
		return (0);

	rdo = read(fl, bf, letters);
	if (rdo == -1)
		return (0);

	bf[letters] = '\0';

	wri = write(1, bf, rdo);
	if (wri == -1)
		return (0);

	close(fl);
	free(bf);
	return (wri);
}
