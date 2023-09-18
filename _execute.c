#include "shell.h"

/**
 * _execute - function that executes the program
 *
 * @comd: the command written by the user
 * @av: array of the command
 * @indx: input of function
 *
 * Return: retrieve the exit status of a child process after it has executed
 */

int _execute(char **comd, char **av, int indx)
{
	pid_t child;
	int status;
	char *full_cmd = _getpath(comd[0]);

	if (!full_cmd)
	{
		printerr(av[0], comd[0], indx);
		freearray(comd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(comd[0], comd, environ) == -1)
		{
			perror(av[0]);
			freearray(comd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(comd);
	}
	return (WEXITSTATUS(status));
}
