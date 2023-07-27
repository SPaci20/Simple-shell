#include "shell.h"

/**
 * set_env - Initializes a new environment variable or modifies an existing one
 * @command: tokenized command containing VARIABLE and VALUE
 *
 * Return: 0 on success, -1 on failure
 */
int set_env(char **command)
{
	char *var, *value;

	if (!command[1] || !command[2])
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return -1;
	}

	var = command[1];
	value = command[2];
	if (setenv(var, value, 1) == -1)
	{
		perror("setenv");
		return -1;
	}

	return 0;
}

/**
 * unset_env - Removes an environment variable
 * @command: tokenized command containing VARIABLE
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env(char **command)
{
	char *var;

	if (!command[1])
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return -1;
	}

	var = command[1];
	if (unsetenv(var) == -1)
	{
		perror("unsetenv");
		return -1;
	}

	return 0;
}

