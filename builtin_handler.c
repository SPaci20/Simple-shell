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
	}
	else if (strcmp(*command, builtin.exit) == 0)
	{
		/* Check if "exit" command has an argument */
		if (command[1] != NULL)
		{
			/* Convert the argument to an integer */
			int exit_status = atoi(command[1]);
			/* Free the memory */
			free(line);
			free_buffers(command);
			/* Exit the shell with the specified status code */
			exit(exit_status);
		}
		else
		{
			/* Exit the shell with the default status code 0 */
			free(line);
			free_buffers(command);
			exit(0);
		}
	}
	/* The command is not a builtin */
	return (0);
}
