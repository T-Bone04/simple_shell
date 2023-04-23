#include "shell.h"
#include <stdlib.h>

/**
 *my_exit- exits the shell.
 *@argu: arrays of args.
 *
 *Return: Always return 0 to exit.
 */
int my_exit(char **argu)
{
	int status = 0;

	if (argu[1] != NULL)
	{
		status = atoi(argu[1]);
	}

	exit(status);/*exits the program with a status or message*/
}
