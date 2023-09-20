#include "shell.h"
/**
 * free_data_recurrent - frees the fields needed for each loop
 * @data: the pointer to the program's data struct
 * Return: Nothing
 */

void free_data_recurrent(data_of_program *data)
{
	if (data->tokens)
		free_pointers_array(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_data_all - frees all whole field of the data
 * @data: the pointer to the program's data struct
 * Return: nothing
 */
void free_data_all(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_data_recurrent(data);
	free_pointers_array(data->env);
	free_pointers_array(data->alias_list);
}

/**
 * free_pointers_array - frees each pointer of an array of pointers
 *                          and the array too
 * @array: the array of pointers
 * Return: nothing
 */

void free_pointers_array(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
