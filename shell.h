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
#include <errno.h>
#include <stddef.h>

#define BUFSIZE 1024
#define STDIN_FILENO 1
#define NULL ((void *)0)

extern char **environ;

/**
 *Struct sliststr - linked lists singly.
 *@numf: field of a number.
 *@strng: string.
 *@next: next node pointer.
 */
typedef struct sliststr
{
	int numf;
	char *strng;
	struct sliststr *nxtpn;
} slist_t;

/**
 *struct continfo - have pseudo-arguements that need to be passed into a
 *function, while allowing same prototype for function pointer 
 *structure.
 *@env: lists that are linked local, copy of envir.
 *@envir: environ's copy  custom modified.
 *@envir_c: if environ is changed.
 */
typedef struct continfo
{
	slist_t *env;
	char **envir
	int envir_c;
} data_t;

/* int execve(const char *pathname, char *const argv[], char *const envp[]); */
void execmd(char **argv);

/*exitt.c*/
void exit(int status);
/*environ.c*/
char **get_envir(data_t *);
int un_setenv(data_t *, char *);
int set_env(data_t *, char *, char *);

/*built_cd.c*/
int my_cd(char **argu);

#endif
