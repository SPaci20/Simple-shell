#include "shell.h"

/**
 * strcmp - compares two strings
 * @s1: compared to s2
 * @s2: compared to s1
 *
 * Return: returns difference between strings
 */
int strcmp(const char *s1, const char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
	{
		i++;
	}
	output = (*(s1 + i) - *(s2 + i));
	return (output);
}

/**
 * strlen - returns the length of a string
 * @s: string passed
 *
 * Return: returns length of string passed
 */
size_t strlen(const char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * strncmp - compares two strings up to n bytes
 * @s1: compared to s2
 * @s2: compared to s1
 * @n: number of bytes
 *
 * Return: difference between s1 and s2
 */
int strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < (int)n; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((s1[i] - s2[i]));
		}
	}
	return (0);
}

/**
 * _strdup - Duplicates a string.
 * @s: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string, or NULL if insufficient memory.
 */
char *_strdup(const char *s)
{
	char *dup;
	int i, len = 0;

	while (s[len] != '\0')
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * strchr - locates a character in a string
 * @s: string to be checked
 * @c: character to be located
 *
 * Return: returns pointer to first occurrence of character
 * or NULL if character not found
 */
char *strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (!c)
	{
		return ((char *)s);
	}
	return (NULL);
}
