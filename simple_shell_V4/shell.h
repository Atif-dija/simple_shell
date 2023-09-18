#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void display_prompt(void);
char *read_user_input(void);
void execute_command(char *command);
void handle_error(void);
void handle_eof(void);

#endif
