#include "shell.h"

/**
 * _getenv - retrieve the value of an environment variable
 *
 * @var: a pointer to a null-terminated string containing
 * the name of the environment variable
 *
 * Return: a pointer to the value associated with that variable if it exists
 * or return NULL
 */

char *_getenv(char *var)
{
	char *tmp, *val, *env, *key;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
