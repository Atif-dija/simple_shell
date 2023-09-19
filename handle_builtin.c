#include "shell.h"

/**
 * is_builtin - checks builtins
 *
 * @cmd: command to execute
 *
 * Return: 1 if command exist 0 if not
 */

int is_builtin(char *cmd)
{
	char *builtins[] = {"exit", "env",
		"setenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}



/**
 * handle_builtin - handle built-in
 *
 * @cmd: command to execute
 * @av: array of string
 * @status: integer used to exit the shell
 * @indx: index
 */

void handle_builtin(char **cmd, char **av, int *status, int indx)
{
	(void) av;
	(void) indx;

	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, status);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);
}

/**
 * exit_shell - exit the progtamme of shell
 *
 * @cmd: command to execute
 * @status: integer used to exit the shell
 */

void exit_shell(char **cmd, int *status)
{
	freearray(cmd);
	exit(*status);
}

/**
 * print_env -  prints the current environment
 *
 * @cmd: command to execute
 * @status: integer used to exit the shell
 */

void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(cmd);
	(*status) = 0;
}

