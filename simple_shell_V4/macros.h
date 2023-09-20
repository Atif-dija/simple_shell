#ifndef _HELPERS
#define _HELPERS


#define PROMPT_MSG "$"
#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024

#define HELP_CD_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"       Change the current working directory.\n\n"\
"       If no argument is given, 'cd' will change the directory to the user's home.\n"\
"       If the argument is '-', 'cd -' will change the directory to the previous one.\n\n"

#define HELP_EXIT_MSG "exit=\n"\
"exit:\texit [STATUS]\n\n"\
"       Exit the simple shell.\n\n"\
"       Exits the shell with a status code of N. If N is omitted, the exit status\n"\
"       is that of the last executed command.\n\n"

#define HELP_ENV_MSG "env=\n"\
"env:\tenv \n\n"\
"       Print environment variables.\n\n"\
"       The 'env' command will print a complete list of environment variables.\n\n"

#define HELP_SETENV_MSG "setenv=\n"\
"setenv:\tsetenv VARIABLE VALUE\n\n"\
"       Change or add an environment variable.\n\n"\
"       Initialize a new environment variable or modify an existing one.\n"\
"       When an incorrect number of arguments is given, an error message is displayed.\n\n"

#define HELP_UNSETENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VARIABLE\n\n"\
"       Delete a variable from the environment.\n\n"\
"       The 'unsetenv' function removes a variable from the environment.\n"\
"       When an incorrect number of arguments is given, an error message is displayed.\n\n"

#define HELP_MSG "help=\n"\
"help:\thelp [BUILTIN_NAME]\n\n"\
"       Display information about builtin commands.\n\n"\
"       Displays brief summaries of builtin commands. If BUILTIN_NAME is specified,\n"\
"       gives detailed help on all commands matching BUILTIN_NAME. Otherwise, the\n"\
"       list of help topics is printed. BUILTIN_NAME list.\n"\
"       Arguments:\n\n"\
"       BUILTIN_NAME specifying a help topic.\n\n"\
"       cd\t[dir]\n"\
"       exit\t[status]\n"\
"       env\n"\
"       setenv\t[variable value]\n"\
"       unset\t[variable]\n"\
"       help\t[built_name]\n\n"

#endif
