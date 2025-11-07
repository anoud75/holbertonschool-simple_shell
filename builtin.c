#include "shell.h"

/**
 * print_env - Print the environment variables
 *
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	if (environ == NULL)
		return;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

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
	(void)last_status;

	if (args == NULL || args[0] == NULL)
		return (0);

	/* Check for exit built-in */
	if (strcmp(args[0], "exit") == 0)
	{
		return (-1); /* Signal to exit, main will handle actual exit */
	}

	/* Check for env built-in */
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1); /* Built-in was executed */
	}

	/* Not a built-in command */
	return (0);
}
