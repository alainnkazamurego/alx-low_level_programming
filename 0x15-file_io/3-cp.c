#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - check the code
 * @argc: arguments counter
 * @argv: array for arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int ff_fd, ft_fd;
	int r;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	ff_fd = open(argv[1], O_RDONLY);
	if (ff_fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	ft_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((r = read(ff_fd, buf, BUFSIZ) > 0))
	{
		if (ft_fd == -1 || write(ft_fd, buf, r) != r)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(ff_fd) == -1 || close(ft_fd) == -1)
	{
		if (close(ff_fd) == -1)
			dprintf(2, "Error: Can't close fd %d\n", ff_fd);
		if (close(ft_fd) == -1)
			dprintf(2, "Error: Can't close fd %d\n", ft_fd);
		exit(100);
	}
	return (1);
}
