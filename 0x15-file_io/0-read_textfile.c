#include "main.h"


/**
 * read_textfile - read text file `filename` and print to POSIX STDOUT
 * @filename: name of file to read
 * @letters: number of letters to read from file `filename`
 * Return: string_sz - no of letters read during function runtime
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf = malloc(letters);
	ssize_t fd, string_sz, read_sz;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	read_sz = read(fd, buf, letters);
	if (read_sz == -1)
		return (0);

	string_sz = write(STDOUT_FILENO, buf, read_sz);
	if (string_sz == -1)
		return (0);

	close(fd);

	free(buf);

	return (string_sz);
}
