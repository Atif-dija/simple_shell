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
	char *line = NULL, **comd = NULL;
	int status = 0, indx = 0;
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

		indx++;
		comd = _token(line);

		if (!comd)
			continue;
		if(is_builtin(comd[0]))
			handle_builtin(comd, av, &status, indx);
		else
			status = _execute(comd, av, indx);
	}

	return (0);
}
