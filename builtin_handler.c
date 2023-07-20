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
	/* Check if the command is a builtin */
	struct builtin builtin = {"env", "exit"};

	if (strcmp(*command, builtin.env) == 0)
	{
		/* Print the environment */
		print_env();
		return (1);
	} else if (strcmp(*command, builtin.exit) == 0)
	{
		/* Exit the shell */
		exit_cmd(command, line);
		return (1);
		}
	/* The command is not a builtin */
	return (0);
}

