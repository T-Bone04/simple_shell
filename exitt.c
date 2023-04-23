#include "shell.h"
#include <stdlib.h>

/**
 *my_exit- exits the shell.
 *@argu: arrays of args.
 *
 *Return: Always return -1.
 */
int my_exit(char **argu)
{
	int exit_mssg = 0;

	if (argu[1] != NULL)
	{
		exit_mssg = atoi(argu[1]);
	}

	exit(exit_mssg);/*exits the program with a status or message*/
}
