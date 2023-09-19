#include "shell.h"

/**
 * _getpath - Handle the PATH
 *
 * @cmd: input of function
 *
 * Return: a pointer to the path or return NULL
 */

char *_getpath(char *cmd)
{
	char *path_env, *D, *full_cmd;
	int i;
	struct stat s;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &s) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	D = strtok(path_env, ":");
	while (D)
	{
		full_cmd = malloc(_strlen(D) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, D);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &s) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			D = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
