#include "shell.h"
/**
 * main - initializes the variables of the program
 * @argc: the number of values received from the command line
 * @argv: the values received from the command line
 * @env: the number of values received from the command line
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	data_inicialize(data, argc, argv, env);

	signal(SIGINT, ctrl_c_handler);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	loop(prompt, data);
	return (0);
}

/**
 * ctrl_c_handler - prints the prompt in a new line when the signal
 *                  SIGINT (ctrl + c) is sent to the program
 * @UNUSED: the prototype option
 */

void ctrl_c_handler(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * data_inicialize - initializes the struct with the info of the program
 * @data: the pointer to the program's data struct
 * @argv: the array of arguments passed to the program's execution
 * @argc: the number of values received from the command line
 * @env: the environment passed to the program's execution
 */

void data_inicialize(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = duplicate_string(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
/**
 * loop - an infinite loop that displays the prompt and processes user input
 * @prompt: the prompt to be displayed
 * @data: the pointer to the program's data struct
 */

void loop(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = get_line(data);

		if (error_code == EOF)
		{
			free_data_all(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			alias_expand(data);
			variables_expand(data);
			tokenizer(data);
			if (data->tokens[0])
			{
				error_code = execute_command(data);
				if (error_code != 0)
					_error_print(error_code, data);
			}
			free_data_recurrent(data);
		}
	}
}
