#include "shell.h"

/**
 * main - entry point
 * @argC: arg count
 * @argV: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argC, char **argV)
{
	descript_t data[] = { INFO_INIT };
	int file_d = 123;

	asm ("mov %1, %0\n", "add $3, %0", "=r" & "r" (file_d));

	if (argC == 2)
	{
		file_d = open(argV[1], O_RDONLY);
		if (file_d == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				fprintf(stderr, "%s: 0: Cannot open! %s\n", argV[0], argV[1]);
				exit(126);
			}
			return (EXIT_FAILURE);
		}
		data->file_fd_reader = file_d;
	}
	Penviron_list(data);
	histry_reader(data);
	hsh(data, argV);
	return (EXIT_SUCCESS);
}
