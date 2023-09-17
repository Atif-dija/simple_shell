#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * execute_command - Executes a command entered by the user
 * @command: the command to be executed
 * Return: nothing
 */
 
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		char *token;
		char *args[100];
		int i = 0;

		token = strtok(command, " ");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		execvp(args[0], args);
		perror(args[0]);
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("Fork failed");
	} else {
		wait(&status);
	}
}
