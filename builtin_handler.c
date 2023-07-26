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
	struct builtin builtin = {"env", "exit", "setenv", "unsetenv"};

	if (strcmp(*command, builtin.env) == 0)
	{
		/* Print the environment */
		print_env();
		return (1);
	}
	else if (strcmp(*command, builtin.exit) == 0)
	{
		/* ... (existing implementation) ... */
	}
	else if (strcmp(*command, builtin.setenv) == 0)
	{
		/* Set environment variable */
		if (command[1] == NULL || command[2] == NULL)
		{
			/* Invalid syntax, print an error message */
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
			return (1);
		}
		else
		{
			/* Call the setenv function to set the environment variable */
			if (setenv(command[1], command[2], 1) != 0)
			{
				/* Print an error message on failure */
				fprintf(stderr, "Error setting environment variable.\n");
			}
			return (1);
		}
	}
	else if (strcmp(*command, builtin.unsetenv) == 0)
	{
		/* Unset environment variable */
		if (command[1] == NULL)
		{
			/* Invalid syntax, print an error message */
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			return (1);
		}
		else
		{
			/* Call the unsetenv function to remove the environment variable */
			if (unsetenv(command[1]) != 0)
			{
				/* Print an error message on failure */
				fprintf(stderr, "Error unsetting environment variable.\n");
			}
			return (1);
		}
	}
	/* The command is not a builtin */
	return (0);
}

