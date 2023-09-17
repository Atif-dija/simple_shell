#include "error_handling.h"
char error_message[] = "Error: ";

void print_error(char *msg)
{
    int i;

    for (i = 0; msg[i] != '\0'; i++) {
        write(STDERR_FILENO, &msg[i], 1);
    }
    write(STDERR_FILENO, ": ", 2);

    for (i = 0; error_message[i] != '\0'; i++) {
        write(STDERR_FILENO, &error_message[i], 1);
    }
    write(STDERR_FILENO, "\n", 1);
}

