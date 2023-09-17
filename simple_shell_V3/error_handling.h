#ifndef _ERROR_HANDLING_H_
#define _ERROR_HANDLING_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char error_message[];

void print_error(char *msg);

#endif /* _ERROR_HANDLING_H_ */

