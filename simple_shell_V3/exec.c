#include "exec.h"

int exec(char *line)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execlp("/bin/sh", "sh", "-c", line, NULL) == -1) {
            print_error(line);
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        print_error("fork");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

