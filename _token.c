#include "shell.h"

/**
 * _token - return the  array of command execute by the user
 *
 * @line: input of function
 *
 * Return: array of command
 */
char **_token(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **com = NULL;
	int c = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		c++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);
	tmp = NULL;
	com = malloc(sizeof(char *) * (c + 1));
	if (!com)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		com[i++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	free(line);
	com[i] = NULL;
	return (com);
}
