#include "shell.h"
int file_check(char *full_path);

/**
 * find_program - finds a program in the system's PATH
 * @data: the pointer to the program's data struct
 * Return: 0 if success, error code if otherwise
 */

int find_program(data_of_program *data)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (file_check(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = concat_string(duplicate_string("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = path_tokenize(data);

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{
		directories[i] = concat_string(directories[i], data->tokens[0]);
		ret_code = file_check(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = duplicate_string(directories[i]);
			free_pointers_array(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_pointers_array(directories);
	return (ret_code);
}

/**
 * path_tokenize - tokenizes the path in directories
 * @data: the pointer to the program's data struct
 * Return: an array of path directories
 */

char **path_tokenize(data_of_program *data)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = get_env_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = duplicate_string(PATH);

	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	tokens = malloc(sizeof(char *) * counter_directories);

	i = 0;
	tokens[i] = duplicate_string(_stringtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = duplicate_string(_stringtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * file_check - checks if a file exists, if its a directory
 *              and if its executable
 * @full_path: the pointer to the full file name
 * Return: 0 on success, error code otherwise
 */

int file_check(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
