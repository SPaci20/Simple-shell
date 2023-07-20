#include "shell.h"

/**
 * free_buffers - frees buffers
 * @buf: buffer to be freed
 *
 * Return: no return
 */
void free_buffers(char **buf)
{
	int i;
	/* Check if the buffer is null */
	if (!buf || buf == NULL)
	{
		return;
	}
	/* Iterate through the buffer and free each element */
	for (i = 0; buf[i] != NULL; i++)
	{
		free(buf[i]);
	}

	/* Free the buffer itself */
	free(buf);
}

