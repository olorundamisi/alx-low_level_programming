#include "main.h"


/**
 * close_w - close_w function parameters
 * @fdread: read
 * @fdwrite: write
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

int main(int argc, char **argv)
{
	int file_from, file_to, n;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((n = read(file_from, buf, 1024)) > 0)
	{
		if (write(file_to, buf, n) != n || file_to == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	close_w(fdread, fdwrite);

	return (0);
}
