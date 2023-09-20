#include "shell.h"
/**
 * update_env - shows the environment where the shell runs
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int update_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	if (data->tokens[1] == NULL)
		print_environment(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{
				var_copy = duplicate_string(get_env_key(cpname, data));
				if (var_copy != NULL)
					set_env_key(cpname, data->tokens[1] + i + 1, data);

				print_environment(data);
				if (get_env_key(cpname, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					set_env_key(cpname, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * set_env - sets an environment variable
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int set_env(data_of_program *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	set_env_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * unset_env - unsets an environment variable
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int unset_env(data_of_program *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	remove_env_key(data->tokens[1], data);

	return (0);
}
