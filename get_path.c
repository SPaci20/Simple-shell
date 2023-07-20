#include "shell.h"

/**
 * find_path - finds the path from the global environment
 *
 * Return: NULL if path is not found or path if path is found.
 */
char *find_path(void)
{
	char *path;
	int x;

	path = getenv("PATH");
	if (path == NULL)
	{
		return (path);
	}

	x = 0;
	while (path[x] != '\0')
	{
		if (strchr(path + x, ':') != NULL)
		{
			return (0);
		}
		x++;
	}

	return (path);
}

