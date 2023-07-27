#include "shell.h"

/**
 * cd_builtin - handles the cd command (change directory)
 * @command: tokenized command
 *
 * Return: no return
 */
void cd_builtin(char **command)
{
	char *new_dir;
	char *prev_dir;

	if (command[1] == NULL)
	{
		/* No argument provided, change to the home directory */
		new_dir = getenv("HOME");
	}
	else if (strcmp(command[1], "-") == 0)
	{
		/* Change to the previous directory */
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = command[1];
	}

	/* Get the current working directory for updating OLDPWD */
	prev_dir = getcwd(NULL, 0);
	if (prev_dir)
	{
		setenv("OLDPWD", prev_dir, 1);
		free(prev_dir);
	}

	/* Change the current working directory */
	if (chdir(new_dir) == -1)
	{
		perror("cd");
	}
	else
	{
		/* Update PWD environment variable with the new directory */
		prev_dir = getcwd(NULL, 0);
		if (prev_dir)
		{
			setenv("PWD", prev_dir, 1);
			free(prev_dir);
		}
	}
}
