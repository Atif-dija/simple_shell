#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void display_prompt(void)
{
    /* write(STDOUT_FILENO, "$", 1); */
}

char *read_user_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1)
    {
        if (feof(stdin))
        {
            write(STDOUT_FILENO, "\n", 1);
            free(line);
            exit(EXIT_SUCCESS);
        }
        perror("getline");
        free(line);
        exit(EXIT_FAILURE);
    }

    if (line[read - 1] == '\n')
    {
        line[read - 1] = '\0';
    }

    return line;
}

void execute_command(char *command)
{
    if (fork() == 0)
    {
        if (execl("/bin/sh", "/bin/sh", "-c", command, NULL) == -1)
        {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}

void handle_error(void)
{
    /* Add error handling code here */
}

void handle_eof(void)
{
    write(STDOUT_FILENO, "\n", 1);
    exit(EXIT_SUCCESS);
}

