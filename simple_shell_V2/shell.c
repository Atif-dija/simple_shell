#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * execute_command - Executes a command entered by the user
 * @command: the command to be executed
 * Return: nothing
 */

void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        char *args[100];
        int i = 0;

        char *token = strtok(command, " ");
        while (token != NULL && i < 99)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        execvp(args[0], args);

        fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Fork failed");
    }
    else
    {
        wait(&status);
    }
}
