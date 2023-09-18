#include "shell.h"

/**
 * freearray - free an array of string
 *
 * @ar: an array
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
	free(ar);
}
