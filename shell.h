/* This is a header guard to prevent multiple inclusion of the same header file */
#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>

/* Function declaration to print the prompt */
void print_prompt(char *prompt);

/* Function declaration to read user input from stdin */
int read_input(char **lineptr, size_t *n);

/* Function declaration to exit the shell */
void exit_shell();

/* Function declaration to safely allocate memory */
void *safe_malloc(size_t size);

/* Function declaration to count the number of tokens in a string */
int count_tokens(char *str, const char *delim);

/* Function declaration to split a string into tokens */
void split_string(char **argv, char *lineptr, const char *delim);

/* Function declaration to execute a command */
void execute_command(char **argv);

/* End of header guard */
#endif
