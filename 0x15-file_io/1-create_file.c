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
	int fdo, wri;
	int soi = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		open(filename, O_CREAT, 0600);
	}

	fdo = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fdo == -1)
	{
		return (-1);
	}

	if (text_content)
	{
		while (text_content[soi])
		{
			soi++;
		}
		wri = write(fdo, text_content, soi);

		if (wri != soi)
		{
			return (-1);
		}
	}
	close(fdo);
	return (1);
}
