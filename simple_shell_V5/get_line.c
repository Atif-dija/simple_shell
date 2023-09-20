#include "shell.h"
/**
* get_line - function that reads one line from the prompt
* @data: the pointer to the program's data struct
* Return: the number of bytes read
*/

int get_line(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}
		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);
		i = 0;
		do {
			array_commands[i] = duplicate_string(_stringtok(i ? NULL : buff, "\n;"));
			i = check_logic(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}

	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (length_string(data->input_line));
}


/**
* check_logic - a function that checks and splits || and && operators
* @array_commands: the array of the commands
* @i: the index in the array_commands to be checked
* @array_operators: the array of the logical operators
*                   for each previous command
* Return: the index of the last command in the array_commands
*/
int check_logic(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = duplicate_string(array_commands[i]);
			array_commands[i + 1] = duplicate_string(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = duplicate_string(array_commands[i]);
			array_commands[i + 1] = duplicate_string(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
