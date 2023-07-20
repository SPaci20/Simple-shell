#include "shell.h"

/**
 * print_env - prints the environment string to stdout
 *
 * Return: 0
 */
void print_env(void)
{
	int x = 0;
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		x++;
		env++;
	}
}
