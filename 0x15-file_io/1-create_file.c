#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * create_file - Entry Point
 * @filename: file name
 * @text_content: null terminated string
 * Return: 1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wr;
	int s = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		open(filename, O_CREAT, 0600);
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content)
	{
		while (text_content[s])
		{
			s++;
		}
		wr = write(fd, text_content, s);

		if (wr != s)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
