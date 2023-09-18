#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define DELIM " \t\n"
extern char **environ;

char *_getline(void);
char **_token(char *line);
int _execute(char **comd, char **av, int indx);
char *_getenv(char *var);
char *_getpath(char *cmd);

char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);

void freearray(char **ar);
char *_itoa(int n);
void reverse_str(char *str, int len);
void printerr(char *name, char *cmd, int indx);

#endif
