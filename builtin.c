#include "shell.h"

/**
 * handle_builtin - Handle built-in commands
 * @args: Array of command arguments
 *
 * Return: 1 if builtin was executed, 0 if not a builtin, -1 to exit shell
 */
int handle_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	/* Check for exit built-in */
	if (strcmp(args[0], "exit") == 0)
	{
		return (-1); /* Signal to exit the shell */
	}

	/* Not a built-in command */
	return (0);
}
