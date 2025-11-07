#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Exit status of last command
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *trimmed = NULL;
	int cmd_count = 0;
	int exec_status;
	int last_status = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		trimmed = trim_spaces(line);

		if (trimmed[0] != '\0')
		{
			cmd_count++;
			exec_status = execute_command(trimmed, argv[0], cmd_count, &last_status);

			/* Check if exit was called */
			if (exec_status == -1)
			{
				free(line);
				break;
			}
		}

		free(line);
	}

	return (last_status);
}
