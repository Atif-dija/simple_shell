#include "shell.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point of the shell program
 * Return: Always 0
 */

int main(void)
{
	char *input = NULL;

	do {
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			printf("$ ");
		fflush(stdout);

		input = read_line();

		if (input != NULL)
		{
			execute_command(input);
			free(input);
		}

	} while (1);

	return (0);
}
