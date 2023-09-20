#include "shell.h"
/**
 * variables_expand - expands the variables
 * @data: the pointer to the program's data struct
 * Return: nothing
 */

void variables_expand(data_of_program *data)
{
    int i;
    char line[BUFFER_SIZE] = {0}, result[BUFFER_SIZE] = {'\0'};

    if (data->input_line == NULL)
        return;

    buffer_add(line, data->input_line);

    for (i = 0; line[i]; i++) {
        if (line[i] == '#' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
        {
            /* Comment detected, stop processing */
            break;
        }

        if (line[i] == '$' && line[i + 1] == '?')
        {
            /* Process $? case */
        }
        else if (line[i] == '$' && line[i + 1] == '$')
        {
            /* Process $$ case */
        }
        else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
        {
            /* Ignore $ followed by space or end of string */
            continue;
        }
        else {
            result[length_string(result)] = line[i]; /* Copy non-special characters */
        }
    }

    if (!compare_string(data->input_line, result, 0))
    {
        free(data->input_line);
        data->input_line = duplicate_string(result);
    }
}


/**
 * alias_expand - expands the aliases
 * @data: the pointer to the program's data struct
 * Return: nothing
 */

void alias_expand(data_of_program *data)
{
	int i, j, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	buffer_add(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = retrieve_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			line[i] = '\0';
			buffer_add(line, temp);
			line[length_string(line)] = '\0';
			buffer_add(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = duplicate_string(line);
	}
}

/**
 * buffer_add - appends the string at end of the buffer
 * @buffer: the buffer to be filled
 * @str_to_add: the string to be copied in the buffer
 * Return: nothing
 */

int buffer_add(char *buffer, char *str_to_add)
{
	int length, i;

	length = length_string(buffer);
	for (i = 0; str_to_add[i]; i++)
	{
		buffer[length + i] = str_to_add[i];
	}
	buffer[length + i] = '\0';
	return (length + i);
}
