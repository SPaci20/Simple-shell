#include "shell.h"

/**
 * execution - executes commands entered by users
 * @cp: command
 * @cmd: vector array of pointers to commands
 * Return: 0
 */
void execution(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	/* Fork a child process */
	child_pid = fork();
	if (child_pid < 0)
	{
		/* Error forking */
		perror(cp);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		/* Execute the command */
		execve(cp, cmd, env);
		/* Error executing command */
		perror(cp);
		/* Free the command string */
		free(cp);
		/* Free the command buffers */
		free_buffers(cmd);
		/* Exit with error code */
		exit(98);
	}
	else
	{
		/* Parent process */
		/* Wait for the child process to exit */
		wait(&status);
	}
}
