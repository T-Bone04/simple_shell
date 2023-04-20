#include "shell.h"

/* boilerplate code to main.c file */
int main(int ac, char **argv)
{
	char *prompt = "shell$ "; /* Printing a prompt */
	char *lineptr; /* Reading and printing what the end user types out */
	size_t n = 0;
	ssize_t nchars_read;

	/* declearing void variables */
	(void)ac; (void)argv;

	/* create an infinte loop */
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
		
		printf("%s\n", lineptr);
   		free(lineptr); /* free up allocated memory */
	}

	return (0);
}

