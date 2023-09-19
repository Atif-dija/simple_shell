#include "shell.h"

/**
 * freearray - free an array of string
 *
 * @ar: an array
 *
 */

void freearray(char **ar)
{
	int i;

	if (!ar)
		return;
	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}
	free(ar), ar = NULL;
}

/**
 * _itoa - convert an integer to a string
 *
 * @n: input of function
 *
 * Return: a pointer to a string
 *
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_str - reverse a string
 *
 * @str: a string
 * @len: length of a string
 */

void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * printerr - print error
 *
 * @name: name of shell
 * @cmd: command
 * @indx: index of command
 */

void printerr(char *name, char *cmd, int indx)
{
	char *idx, msg[] = ": not found\n";

	idx = _itoa(indx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(idx);
}
