#include "shell.h"
/**
 * get_env_key - retrieves the value of an environment variable
 * @key: the environment variable of interest
 * @data: the pointer to the program's data struct
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */

char *get_env_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_length = length_string(key);

	for (i = 0; data->env[i]; i++)
	{
		if (compare_string(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			return (data->env[i] + key_length + 1);
		}
	}
	return (NULL);
}

/**
 * set_env_key - sets or overwrites the value of an environment variable
 * @key: the name of the variable to set
 * @value: the new value
 * @data: the pointer to the program's data struct
 * Return: 1 if the parameters are NULL, 2 if there is an error, 0 if success
 */

int set_env_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = length_string(key);

	for (i = 0; data->env[i]; i++)
	{
		if (compare_string(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[i]);
			break;
		}
	}
	data->env[i] = concat_string(duplicate_string(key), "=");
	data->env[i] = concat_string(data->env[i], value);

	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * remove_env_key - removes a key from the environment
 * @key: the key to remove
 * @data: the pointer to the program's data struct
 * Return: 1 if the key was removed, 0 if the key does not exist
 */

int remove_env_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = length_string(key);

	for (i = 0; data->env[i]; i++)
	{
		if (compare_string(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			free(data->env[i]);

			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environment - prints the current environment
 * @data: the pointer to the program's data struct
 * Return: nothing
 */

void print_environment(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
