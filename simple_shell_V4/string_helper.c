#include "shell.h"
/**
 * length_string - returns the length of a string
 * @string: the pointer to the string
 * Return: the length of string
 */

int length_string(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * duplicate_string - duplicates a string
 * @string: the string to be copied
 * Return: the pointer to the array
 */

char *duplicate_string(char *string)
{
	char *result;
	int length, i;

	if (string == NULL)
		return (NULL);

	length = length_string(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}

/**
 * compare_string - compares two strings
 * @string1: string 1, the shorter
 * @string2: string 2, the longer
 * @number: the number of characters to be compared, 0 if infinite
 * Return: 0 if the strings are different, 1 if they are equal
 */

int compare_string(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (length_string(string1) != length_string(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * concat_string - links two strings
 * @string1: string to be linked
 * @string2: string to be linked
 * Return: the pointer to the array
 */

char *concat_string(char *string1, char *string2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (string1 == NULL)
		string1 = "";
	length1 = length_string(string1);

	if (string2 == NULL)
		string2 = "";
	length2 = length_string(string2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (length1 = 0; string1[length1] != '\0'; length1++)
		result[length1] = string1[length1];
	free(string1);
	for (length2 = 0; string2[length2] != '\0'; length2++)
	{
		result[length1] = string2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * reverse_string - reverses a string
 * @string: the pointer to the string
 * Return: void
 */

void reverse_string(char *string)
{

	int i = 0, length = length_string(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
