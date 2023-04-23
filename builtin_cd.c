#include "shell.h"

/**
 *_updatenv - updates the OLDPWD and PWD environment var.
 *@cwd: current working directory.
 */
void _updatenv(char *cwd)
{
	setenv("PWD", cwd, 1);
	setenv("OLDPWD", getenv("PWD"), 1);
}

/**
 *my_cd - changes the the current working
 *           directory of a shell exec environment.
 *@argu: destinated directory.
 *Return: Always 0.
 */
int my_cd(char **argu)
{
	char *main_dir;
	char *desti_dir;
	char cwd[1024];

	if (argu[1] == NULL)/*if no argument given, it changes to user's home dir*/
	{
		main_dir = getenv("HOME");
		if (main_dir == NULL)
		{
			fprintf(stderr, "my_cd: HOME environment  var not set/n");
			return (1);
		}
		desti_dir = main_dir;
	}
	else if (strcmp(argu[1], "-") == 0)/*if arg to cd is -, changes dir to prev*/
	{
		desti_dir = getenv("OLDPWD");
		if (desti_dir == NULL)
		{
			fprintf(stderr, "my_cd: OLDPWD environment var not set\n");
			return (1);
		}
	}
	else
	{
		desti_dir = argu[1];
	}

	if (chdir(desti_dir) != 0)/*chdir used to change directories*/
	{
		perror("my_cd: chdir failed");/*perror is used to print an error*/
		return (1);
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)/*getcwd retrieves the new working dir*/
	{
		perror("my_cd: getcwd failed");
		return (1);
	}
	else
	{
		_updatenv(char *cwd);
		return (1);
}

