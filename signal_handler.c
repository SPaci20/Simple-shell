#include "shell.h"

/**
 * handle_signal - handles signals
 * @m: the signal number
 *
 * Return: nothing
 */
void handle_signal(int m)
{
	/* Ignore the signal number */
	(void)m;
	/* Write a newline to the standard error stream */
	write(STDERR_FILENO, "\n", 1);
	/* Write a prompt to the standard error stream */
	write(STDERR_FILENO, "$ ", 2);
}
