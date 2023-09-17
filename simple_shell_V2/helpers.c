#include "shell.h"
/**
 * read_line - reads a line of input from the user
 * Return: a pointer to the input string, or NULL on Ctrl+D (end of file)
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	line[read - 1] = '\0';
	return (line);
}
