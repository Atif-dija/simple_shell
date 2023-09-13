#include "shell.h"

/**
 * _token -
 *
 * @line:
 *
 * Return:
 */
char **_token(char *line)
{
	char *token = NULL, tmp = NULL;
	char **com = NULL;
	int c = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
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
		token = sstrtok(NULL, DELIM);
	}
	free(line);
	com[i] = NULL;
	return (com);
}
