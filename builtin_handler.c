#include "shell.h"

/**
 * handle_builtin - handles execution of builtin functions
 * @command: tokenized commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (strcmp(*command, builtin.env) == 0)
	{
		/* Print the environment */
		print_env();
		return (1);
	}
	else if (strcmp(*command, builtin.exit) == 0)
	{
		/* Exit the shell */
		exit_cmd(command, line);
		return (1);
	}
	else if (strcmp(*command, "setenv") == 0)
	{
		/* Initialize a new environment variable or modify an existing one */
		if (set_env(command) == 0)
			return 1;
	}
	else if (strcmp(*command, "unsetenv") == 0)
	{
		/* Remove an environment variable */
		if (unset_env(command) == 0)
			return 1;
	}
	/* The command is not a builtin */
	return (0);
}

