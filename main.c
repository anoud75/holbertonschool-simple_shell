#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;

	(void)argc;
	(void)argv;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		line = read_line();
		if (line == NULL)
			break;

		args = parse_line(line);
		if (args == NULL || args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}

		status = execute_command(args);

		free(line);
		free(args);
	}

	return (0);
}
