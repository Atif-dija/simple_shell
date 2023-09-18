#include "shell.h"
/**
 * main - Entry point of the program
 * Return: Always 0
 */

int main(void)
{
	char *line = NULL, **comm = NULL;
	int i, status = 0;

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
		for (i = 0; comm[i]; i++)
		{
			printf("%s\n", comm[i]);
			free(comm[i]), comm[i] = NULL;
		}
		free(comm), comm = NULL;
	}

	return (0);
}
