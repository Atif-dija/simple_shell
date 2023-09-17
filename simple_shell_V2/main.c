#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	int first_run = 1;

	do
	{
		if (first_run)
		{
			first_run = 0;
		} else {
			printf("$ ");
		}
		read = getline(&input, &len, stdin);

		if (read != -1)
		{
			input[read - 1] = '\0';
			execute_command(input);
		}
		else
		{
			free(input);
			break;
		}

	} while (1);
	return (0);
}