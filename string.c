#include "shell.h"
/**
 * _strcpy -  function that copies the string pointed to by src
 *  including the terminating null byte (\0)
 *  to the buffer pointed to by dest
 *
 *  @src: input pf function
 *  @dest: input of function
 *
 *  Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, length = 0;

	while (*src != '\0')
	for (i = 0; src[i] != '\0'; i++)
	{
		length++;
	}

	for (i = 0; src[i] < length; i++)
	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[length] = '\0';
	return (dest);
}

/**
 * _strcmp - function that compares two strings
 *
 * @s1: input of function
 * @s2: input of function
 *
 * Return: cmp
 */

int _strcmp(char *s1, char *s2)
{
	int n = 0;

	while (s1[n] != '\0' && s2[n] != '\0')
	{
		if (s1[n] != s2[n])
			return (s1[n] - s2[n]);
		n++;
	}
	return (0);
}

/**
 * _strcat -  function appends the src string to the dest string
 *
 * @dest: iput of function
 * @src: input of function
 *
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{

char *s_dest = dest;
char *s_src = src;

	while (*s_dest != '\0')
	{
		s_dest++;
	}

	while (*s_src != '\0')
	{
		*s_dest = *s_src;
		s_dest++;
		s_src++;
	}
	*s_dest = '\0';
	return (dest);
}

/**
 * _strlen - function that returns the length of a string
 *
 * @s: input of function
 *
 * Return: the length of a string
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strdup - takes a null-terminated string as input
 * and creates a new copy of that string
 *
 * @str: string
 *
 * Return: new copy of the string
 */

char _strdup(const char *str)
{
	char *p;
	int i, len = 0;

	if (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		p[i] = str[i];
	return (p);
}
