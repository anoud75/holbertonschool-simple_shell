#include "shell.h"

/**
 * read_line - Reads a line from stdin
 *
 * Return: Pointer to the line read, or NULL on failure/EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}

	if (characters > 0 && line[characters - 1] == '\n')
		line[characters - 1] = '\0';

	return (line);
}
