#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * append_text_to_file - Entry Point
 * @filename: file name
 * @text_content: text content
 * Return: 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fdo, wri;
	int count = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	fdo = open(filename, O_RDWR | O_APPEND, 0666);

	if (fdo == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		while (text_content[count])
		{
			count++;
		}
		wri = write(fdo, text_content, count);
		if (wri != count)
		{
			return (-1);
		}
	}
	close(fdo);
	return (1);
}
