#include "shell.h"

/**
 *my_env - prints the current environment variables.
 *@argu: array of arguments.
 *
 * Return: Always return 0.
 */
int my_env(char **argu)
{
	int j = 0;

	while (environ[j])
	{
		/*writes enviroment var to stdout*/
		write(STDOUT_FILENO, environ[j], strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
	return (0);
}
