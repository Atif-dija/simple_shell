#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * execute_command - Executes a command entered by the user
 * @command: the command to be executed
 * Return: nothing
 */

void execute_command(char *command)
{
	int status = system(command);

	if (status == -1)
	{
		perror("system");
		exit(EXIT_FAILURE);
	}
}
