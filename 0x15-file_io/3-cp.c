#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
/**
 * close_errchk - closes and print
 * an error msg on fails
 *
 * @fd: descriptor to exit
 *
 * Return: 0 on true, -1 on false
 */
int close_errchk(int fd)
{
	int error_h;

	error_h = close(fd);
	if (error_h == -1)
	{
		dprintf(STDERR_FILENO, "Error: unable to close fd %d\n", fd);
		return (100);
	}
	return (0);
}
/**
 * write_err - error ms on error
 *
 * @fd1: descriptor 1 on exit
 * @fd2: descriptor 2 on exit
 * @filename:  prompting the mistake
 *
 * Return: 99
 */
int write_err(int fd1, int fd2, char *filename)
{
	dprintf(STDERR_FILENO, "Error: unable to write to %s\n", filename);
	close_errchk(fd1);
	close_errchk(fd2);
	return (99);
}
/**
 * read_err - error msg for a get error
 *
 * @fd1: descriptor 1 to exit
 * @fd2: descriptor 2 to exit
 * @filename: filename asking the error
 *
 * Return: 98
 */
int read_err(int fd1, int fd2, char *filename)
{
	dprintf(STDERR_FILENO, "Error: unable to read from item %s\n", filename);
	close_errchk(fd1);
	close_errchk(fd2);
	return (98);
}
/**
 * main - copy 1 file to other, new file with permssion 664
 * usage - cp file_from file_to
 *
 * @ac: number of argumetns
 * @av: list of arguments
 *
 * Return: 97 if wrong number of arguments
 * 98 if file_from does not exist or unreadable
 * 99 if write is false
 * 100 if file close is false
 * 0 else
 */
int main(int ac, char *av[])
{
	char buf[1024];
	int lnree, lngwe, file_from, file_to, error_h;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: unable read from file %s\n",
			av[1]);
		return (98);
	}
	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC,
		       S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable write to %s\n", av[2]);
		close_errchk(file_from);
		return (99);
	}
	do {
		lnree = read(file_from, buf, 1024);
		if (lnree == -1)
			return (read_err(file_from, file_to, av[1]));
		lngwe = write(file_to, buf, lnree);
		if (lngwe == -1 || lngwe != lnree)
			return (write_err(file_from, file_to, av[2]));
	} while (lnree == 1024);
	error_h = close_errchk(file_from);
	error_h += close_errchk(file_to);
	if (error_h!= 0)
		return (100);
	return (0);
}
