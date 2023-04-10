#include "main.h"

#define BUF_SIZE 1024


/**
 * close_w - close_w created to reduce space
 * @fdread: fdread
 * @fdwrite: fdwrite
 */

void close_w(int fdread, int fdwrite)
{
	if (close(fdwrite) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdwrite);
		exit(100);
	}

	if (close(fdread) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdread);
		exit(100);
	}
}

/**
 * main - copy the content of file `file_from` to another file `file_to`
 * @argc: argument count - number of arguments
 * @argv: argument vector - array containing arguments
 * Return: number of letters read
 */

int main(int argc, char *argv[])
{
	char buf[BUF_SIZE];
	char *file_from, *file_to;
	int fdread, fdwrite;
	ssize_t rd = 1024, wr;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }

	file_from = argv[1], file_to = argv[2];

	fdread = open(file_from, O_RDONLY);
	if (fdread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98); }

	fdwrite = open(file_to, O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0664);
	if (fdwrite == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99); }

	while (rd == BUF_SIZE)
	{
		rd = read(fdread, buf, BUF_SIZE);
		if (rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			exit(98); }

		wr = write(fdwrite, buf, rd);
		if (wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99); }
	}
	close_w(fdread, fdwrite);
	return (0);
}
