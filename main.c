#include "shell.h"

/**
 * main - simple shell function
 *
 * @argc: The size of the argv
 * @argv: An array of size argc
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	int status = 0;
	(void) argc;
	(void) argv;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			return (status);
		}
		free(line);
	}
}


