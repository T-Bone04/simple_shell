#ifdef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

/* int execve(const char *pathname, char *const argv[], char *const envp[]); */
void execmd(char **argv);
/*ge_tline.c*/
void assign_line(char **buf_str, size_t *n, char *buff, size_t i);
ssize_t _getline(char **buff_str, size_t *n, FILE *stream);

#endif
