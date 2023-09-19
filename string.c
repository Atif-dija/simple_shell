#include "shell.h"
/**
 * _strcpy - function that copies the string pointed to by src
 *  including the terminating null byte (\0)
 *  to the buffer pointed to by dest
 *
 *  @src: input pf function
 *  @dest: input of function
 *
 *  Return: dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
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
	int cmp;

	cmp = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
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
	char *ptr = dest;

	while (*ptr)
		ptr++;

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * _strlen - function that returns the length of a string
 *
 * @s: input of function
 *
 * Return: the length of a string
 */

int _strlen(const char *s)
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

char *_strdup(const char *str)
{
	char *p;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		p[i] = str[i];
	return (p);
}

