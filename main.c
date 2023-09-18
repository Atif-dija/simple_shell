#include "shell.h"
/**
 * main - Entry point of the program
 *
 * @ac: The size of the av
 * @av: An array of size ac
 *
 * Return: Always 0
 */

int main(int ac, char **av)
{
	char *line = NULL, **comm = NULL;
	int i, status = 0;
	(void) ac;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		comm = _token(line);
		if (!comm)
			continue;
		status = _execute(comm, av);
	}

	return (0);
}
