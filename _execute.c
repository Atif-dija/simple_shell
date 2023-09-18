#include "shell.h"

/**
 * _execute - function that executes the program
 *
 * @com: the command written by the user
 * @av: array of the command
 *
 * Return: retrieve the exit status of a child process after it has executed
 */

int _execute(char **com, char **av)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(com[0], com, environ) == -1)
		{
			perror(av[0]);
			freearray(com);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(com);
	}
	return (WEXITSTATUS(status));
}
