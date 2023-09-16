#include "shell.h"
/**
 * main - Entry point of the program
 * Return: Always 0
 */
 
int main(void)
{
	char *input;
	char **commands;
	int exit_status;

	while (1)
	{
		printf("$ ");
		input = _getline();

		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}

		commands = _token(input);

		exit_status = execute(commands, NULL);

		free(input);
		freearray(commands);

		printf("Exit status: %d\n", exit_status);
	}

	return (0);
}
