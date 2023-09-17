#include "prompt.h"

char *prompt(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    write(STDOUT_FILENO, "$ ", 2);

    read = getline(&line, &len, stdin);

    if (read == -1) {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 1);
        free(line);
        return NULL;
    }

    if (read > 0 && line[read - 1] == '\n')
        line[read - 1] = '\0';

    return line;
}

