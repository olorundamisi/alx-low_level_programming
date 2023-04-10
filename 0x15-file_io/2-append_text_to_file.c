#include "main.h"


/**
 * append_text_to_file - append text to file `filename`
 * @filename: name of file to append text to
 * @content: content to append to file `filename`
 * Return: 1 on function success, -1 if function fails
 */

int append_text_to_file(const char *filename, char *content)
{
	int fd, size, fwrite;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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
