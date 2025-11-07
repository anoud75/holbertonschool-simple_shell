#include "shell.h"

/**
 * handle_builtin - Handle built-in commands
 * @args: Array of command arguments
 * @last_status: Last command exit status
 *
 * Return: 1 if builtin was executed, 0 if not a builtin,
 *         -1 to exit shell with last_status
 */
int handle_builtin(char **args, int last_status)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	/* Check for exit built-in */
	if (strcmp(args[0], "exit") == 0)
	{
		/* Exit with the last command's status */
		exit(last_status);
	}

	/* Not a built-in command */
	return (0);
}
