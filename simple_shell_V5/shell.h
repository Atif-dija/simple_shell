#ifndef _SHELL
#define _SHELL
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include "macros.h"

/**
 * struct info - holds essential program information
 * @program_name: the name of the executable
 * @input_line: pointer to the input line read for get_line
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor for input commands
 * @tokens: pointer to an array of tokenized input
 * @env: copy of the environment variables
 * @alias_list: array of pointers containing aliases
 */

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - represents builtin commands
 * @builtin: the name of the builtin command
 * @function: the pointer to the associated function for the command
 */

typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;


void data_inicialize(data_of_program *data, int arc, char *argv[], char **env);
void loop(char *prompt, data_of_program *data);
void ctrl_c_handler(int opr UNUSED);

int get_line(data_of_program *data);
int check_logic(char *array_commands[], int i, char array_operators[]);

void variables_expand(data_of_program *data);
void alias_expand(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add);

void tokenizer(data_of_program *data);
char *_stringtok(char *line, char *delim);

int execute_command(data_of_program *data);

int execute_builtin(data_of_program *data);

char **path_tokenize(data_of_program *data);
int find_program(data_of_program *data);

void free_pointers_array(char **directories);
void free_data_recurrent(data_of_program *data);
void free_data_all(data_of_program *data);

int exit_builtin(data_of_program *data);
int change_directory_builtin(data_of_program *data);
int set_working_directory(data_of_program *data, char *new_dir);
int help_builtin(data_of_program *data);
int alias_builtin(data_of_program *data);

int update_env(data_of_program *data);
int set_env(data_of_program *data);
int unset_env(data_of_program *data);

char *get_env_key(char *name, data_of_program *data);
int set_env_key(char *key, char *value, data_of_program *data);
int remove_env_key(char *key, data_of_program *data);
void print_environment(data_of_program *data);

int _print(char *string);
int _printe(char *string);
int _error_print(int errorcode, data_of_program *data);

int length_string(char *string);
char *duplicate_string(char *string);
int compare_string(char *string1, char *string2, int number);
char *concat_string(char *string1, char *string2);
void reverse_string(char *string);

void string_to_long(long number, char *string, int base);
int _atoi(char *s);
int characters_counter(char *string, char *character);

int alias_print(data_of_program *data, char *alias);
char *retrieve_alias(data_of_program *data, char *alias);
int set_new_alias(char *alias_string, data_of_program *data);


#endif
