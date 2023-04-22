#include "shell.h"

/* boilerplate code to main.c file */
int main(int ac, char **argv)
{
	char *prompt = "shell$ "; /* Printing a prompt */
	char *lineptr = NULL; /* Reading and printing what the end user types out */
	char *lineptr_copy = NULL; /* strtok breaks down da string, copy of to use */
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/* declearing void variables */
	(void)ac;

	/* create an infinte loop and shell prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		/* check if the function getline failed or reached EOF or use CTRL + D */
		if (nchars_read == -1)
		{
			printf("Exiting shell.....\n");
			return (-1);
		}

		/* allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/* copy lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);

		/******** split the string (lineptr) into an array of words ******/
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim);

		/* determine how many tokens are there*/
		while (token != NULL) /* check if it is not null with  help of the while */
		{
			num_tokens++; /* If it is not null we add one to our counter num_tokens */
			token = strtok(NULL, delim); /* call strtok, can get the next token */
		}
		num_tokens++;

		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);

		/* Store each token in the argv array */
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/* execute the command */
		execmd(argv);
	}
		/* printf("%s\n", lineptr); */
		free(lineptr); /* free up allocated memory */
		free(lineptr);

	return (0);
}