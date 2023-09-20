#include "shell.h"
/**
 * string_to_long - converts a number to a string
 * @number: the number to be converted into a string
 * @string: the buffer to save the number as a string
 * @base: the base to convert the number
 * Return: nothing
 */

void string_to_long(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	reverse_string(string);
}


/**
 * _atoi - converts a string to an integer
 * @s: the pointer to the source string
 * Return: int of string or 0
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * characters_counter - counts the coincidences of character in string.
 * @string: the pointer to the source string
 * @character: the string with chars to be counted
 * Return: int of string or 0
 */

int characters_counter(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
