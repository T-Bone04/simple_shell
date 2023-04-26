#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
/* int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}

int main(int ac, char **argv)
{
	char *prompt = "shell$ ";
	char *lineptr;
	size_t n = 0;

  /* declaring void variables */
/*  (void)ac; (void)argv;

		printf("%s", prompt);
		getline(&lineptr, &n, stdin);
		printf("%s\n", lineptr);

		free(lineptr);
	return (0);
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char *full_command = NULL, *copy_command = NULL;
    size_t n = 0;
    ssize_t nchars_read; /* number of characters the user types */
    char *token;
    const char *delim = " \n";
    char **argv;
    int i = 0; // x = 0;
    int num_tokens = 0;

    // strcpy(command_copy, full_command);
    /* print a prompt for the user to type something */
    printf("$ ");

    /* get the string that the user types in and pass it to full_command */
    nchars_read = getline(&full_command, &n, stdin);

    /* let's allocate space to store the characters read by getline */
    copy_command = malloc(sizeof(char) * nchars_read);

    if (copy_command == NULL){
        perror("tsh: memory allocation error");
        return (-1);
    }

    /* make a copy of the command that was typed */
    strcpy(copy_command, full_command);

    /* check if the getline function failed or reached EOF or user use CTRL + D */
    if (nchars_read == -1){
        printf("Exiting shell....\n");
        return (-1);
    }
    else {

        /* split the string (full_command) into an array of words */
        token = strtok(full_command, delim);

        /* allocate space to store the variable arguments but before then determine how many tokens are there*/
        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;
        // printf(">>>>> %d \n", num_tokens);

        /* use malloc to allocate enough space for the pointer to the argument variables */
        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(copy_command, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            // printf(">>>>> %s \n", argv[i]);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the commands with execve */


        free(argv);
        free(full_command);
        free(copy_command);
    }

    return (0);
}

