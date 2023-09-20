#include "shell.h"
/**
 * execute_builtin - searches for a match and executes the associated builtin
 * @data: the pointer to the program's data struct
 * Return: Returns the return value of the executed function
 *         if there is a match, otherwise returns -1
 */

int execute_builtin(data_of_program *data)
{
	int iterator;

	builtins options[] = {
		{"exit", exit_builtin},
		{"help", help_builtin},
		{"cd", change_directory_builtin},
		{"alias", alias_builtin},
		{"env", update_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}
	};
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (compare_string(options[iterator].builtin, data->command_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
