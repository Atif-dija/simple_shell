#include "shell.h"
/**
 * _print - writes an array of characters to standard output
 * @string: pointer to the array of chars
 * Return: the number of bytes written or -1 on error
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, length_string(string)));
}

/**
 * _printe - writes an array of characters to standard output
 * @string: pointer to the array of chars
 * Return: the number of bytes written or -1 on error
 */

int _printe(char *string)
{
	return (write(STDERR_FILENO, string, length_string(string)));
}

/**
 * _error_print - writes an array of characters to standard output
 * @data: the pointer to the program's data struct
 * @errorcode: the error code to be printed
 * Return: the number of bytes written or -1 on error
 */

int _error_print(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	string_to_long((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
