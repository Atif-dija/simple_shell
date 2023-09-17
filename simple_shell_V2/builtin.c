#include "shell.h"
#include "builtin.h"
#include <stdio.h>
#include <string.h>

int is_builtin_command(char *command) {
    return (strcmp(command, "echo") == 0 || strcmp(command, "export") == 0);
}

void execute_builtin_command(char *command) {
    if (strcmp(command, "echo") == 0) {
        /* Implement echo logic */
    } else if (strcmp(command, "export") == 0) {
        /* Implement export logic */
    } else {
        printf("Unknown built-in command: %s\n", command);
    }
}
