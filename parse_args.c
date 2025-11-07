#include "shell.h"

/**
 * parse_args - Parse command line into arguments
 * @line: The command line to parse
 *
 * Return: Array of arguments (NULL-terminated)
 */
char **parse_args(char *line)
{
	char **args = NULL;
	char *token = NULL;
	int i = 0;
	int bufsize = 64;

	if (line == NULL)
		return (NULL);

	args = malloc(sizeof(char *) * bufsize);
	if (args == NULL)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		args[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			args = realloc(args, sizeof(char *) * bufsize);
			if (args == NULL)
				return (NULL);
		}

		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	return (args);
}

/**
 * free_args - Free the argument array
 * @args: The argument array to free
 *
 * Return: void
 */
void free_args(char **args)
{
	if (args != NULL)
		free(args);
}
