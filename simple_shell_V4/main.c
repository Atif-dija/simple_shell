#include "shell.h"

int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_user_input();

        if (*command)
        {
            execute_command(command);
        }
        else
        {
            free(command);
        }
    }

    return (0);
}

