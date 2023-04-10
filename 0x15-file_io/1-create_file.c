#include "main.h"


/**
 * create_file - create file and add content
 * @filename: name of file to create
 * @content: content of file to add to file `filename`
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *content)
{
	int fd, size, fwrite;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (content != NULL)
	{
		for (size = 0; content[size] != '\0'; size++)
			;

		fwrite = write(fd, content, size);
		if (fwrite == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
