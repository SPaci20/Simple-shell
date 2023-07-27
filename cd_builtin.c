#include "shell.h"

/**
 * change_directory - Changes the current directory of the process.
 * @path: The directory to change to.
 *
 * Return: 0 on success, -1 on failure.
 */
int change_directory(char *path)
{
	char *old_pwd = NULL;
	char *new_pwd = NULL;

	/* Save the current working directory */
	old_pwd = getcwd(NULL, 0);
	if (old_pwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	/* Change the current directory */
	if (chdir(path) == -1)
	{
		perror("cd");
		free(old_pwd);
		return (-1);
	}

	/* Update the PWD environment variable */
	new_pwd = getcwd(NULL, 0);
	if (new_pwd == NULL)
	{
		perror("getcwd");
		free(old_pwd);
		return (-1);
	}

	if (setenv("PWD", new_pwd, 1) == -1)
	{
		perror("setenv");
		free(old_pwd);
		free(new_pwd);
		return (-1);
	}

	free(old_pwd);
	free(new_pwd);
	return (0);
}

/**
 * cd_builtin - Implements the cd builtin command.
 * @command: The tokenized command containing cd and optional directory.
 *
 * Return: 1 if cd was executed, 0 if not.
 */
int cd_builtin(char **command)
{
	char *path;

	if (command[1] == NULL)
	{
		/* If no argument is given, change to $HOME */
		path = getenv("HOME");
		if (path == NULL)
		{
			perror("cd");
			return (1);
		}
	}
	else if (strcmp(command[1], "-") == 0)
	{
		/* If the argument is "-", change to the previous directory */
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			perror("cd");
			return (1);
		}
	}
	else
	{
		path = command[1];
	}

	if (change_directory(path) == 0)
	{
		return (1);
	}

	return (0);
}
