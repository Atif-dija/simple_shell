#ifndef _EXEC_H_
#define _EXEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error_handling.h"

int exec(char *line);

#endif /* _EXEC_H_ */

