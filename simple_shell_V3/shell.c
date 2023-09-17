#include "prompt.h"
#include "exec.h"
#include "error_handling.h"

int main(void)
{
    char *line;
    int status = 1;

    do {
        line = prompt();
        if (line != NULL) {
            status = exec(line);
            free(line);
        }
    } while (status);

    return 0;
}

