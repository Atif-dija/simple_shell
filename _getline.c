#include "shell.h"

/**
 * _getline - read lines of text from standard input
 *
 * Return: line of text
 */

char *_getline(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
	n = getline(&line, &size, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

