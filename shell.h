#ifdef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/type.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

#define BUFSIZE 1024
#define STDIN_FILENO 1

/* int execve(const char *pathname, char *const argv[], char *const envp[]); */
void execmd(char **argv);

/*ge_tline.c*/
void assign_line(char **buf_str, size_t *n, char *buff, size_t i);
ssize_t _getline(char **buff_str, size_t *n, FILE *stream);
ssize_t r;
int fflush(FILE *stream);
void *malloc(size_t size);
void free(void *ptr);
ssize_t read(int fildes, void *buf, size_t nbyte);

#endif
