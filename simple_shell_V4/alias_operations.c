#include "shell.h"
/**
 * alias_print - adds, removes or shows aliases
 * @data: the pointer to the program's data struct
 * @alias: the name of the alias to be printed
 * Return: 0 on success, or other number if its declared in the arguments
 */

int alias_print(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = length_string(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (compare_string(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * retrieve_alias - adds, removes or shows aliases
 * @data: the pointer to the program's data struct
 * @name: the name of the requested alias.
 * Return: 0 on success, or other number if it's declared in the arguments
 */
char *retrieve_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = length_string(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (compare_string(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	return (NULL);

}

/**
 * set_new_alias - adds, or overrides aliases
 * @alias_string: alias to be set in the form (name='value')
 * @data: the pointer to the program's data struct
 * Return: 0 on success, or other number if it's declared in the arguments
 */
int set_new_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = retrieve_alias(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (compare_string(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = duplicate_string(buffer);
	}
	else
		data->alias_list[j] = duplicate_string(alias_string);
	return (0);
}
