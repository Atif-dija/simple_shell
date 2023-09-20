#include "shell.h"
/**
 * exit_builtin - exits the program with the specified status
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int exit_builtin(data_of_program *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{
		for (i = 0; data->tokens[1][i]; i++)
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
				&& data->tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_data_all(data);
	exit(errno);
}

/**
 * change_directory_builtin - changes the current directory
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int change_directory_builtin(data_of_program *data)
{
	char *dir_home = get_env_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (compare_string(data->tokens[1], "-", 0))
		{
			dir_old = get_env_key("OLDPWD", data);
			if (dir_old)
				error_code = set_working_directory(data, dir_old);
			_print(get_env_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_working_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_working_directory(data, dir_home));
	}
	return (0);
}

/**
 * set_working_directory - sets the working directory
 * @data: the pointer to the program's data struct
 * @new_dir: the path to be set as the working directory
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int set_working_directory(data_of_program *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!compare_string(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		set_env_key("PWD", new_dir, data);
	}
	set_env_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * help_builtin - displays information about builtins
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int help_builtin(data_of_program *data)
{
	int i, length = 0;
	char *mensajes[6] = {NULL};

	mensajes[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		_print(mensajes[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_CD_MSG;

	for (i = 0; mensajes[i]; i++)
	{
		length = length_string(data->tokens[1]);
		if (compare_string(data->tokens[1], mensajes[i], length))
		{
			_print(mensajes[i] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * alias_builtin - manages aliases
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */

int alias_builtin(data_of_program *data)
{
	int i = 0;

	if (data->tokens[1] == NULL)
		return (alias_print(data, NULL));

	while (data->tokens[++i])
	{
		if (characters_counter(data->tokens[i], "="))
			set_new_alias(data->tokens[i], data);
		else
			alias_print(data, data->tokens[i]);
	}
	return (0);
}
