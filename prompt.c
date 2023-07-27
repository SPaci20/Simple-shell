#include "shell.h"

/**
 * prompt_user - prints a prompt to the user
 *
 * Return: no return
 */
void prompt_user(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		flags.interactive = 1;
	}
	if (flags.interactive)
	{
		write(STDERR_FILENO, "$ ", 2);
	}
}

