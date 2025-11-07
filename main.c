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
	int cmd_count = 0;
	int status;

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

		cmd_count++;
		status = execute_command(line, argv[0], cmd_count);
		free(line);

		if (status == 0)
			break;
	}

	return (0);
}
