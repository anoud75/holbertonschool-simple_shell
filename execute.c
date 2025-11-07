#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @command: The command line to execute
 * @program_name: Name of the shell program (for error messages)
 * @cmd_count: Current command count
 *
 * Return: 1 to continue execution, 0 to exit
 */
int execute_command(char *command, char *program_name, int cmd_count)
{
	pid_t pid;
	int status;
	char **args = NULL;
	struct stat st;
	char *cmd_copy = NULL;

	if (command == NULL || command[0] == '\0')
		return (1);

	cmd_copy = strdup(command);
	if (cmd_copy == NULL)
		return (1);

	args = parse_args(cmd_copy);
	if (args == NULL || args[0] == NULL)
	{
		free(cmd_copy);
		free_args(args);
		return (1);
	}

	if (stat(args[0], &st) == -1)
	{
		print_error(program_name, cmd_count, args[0]);
		free(cmd_copy);
		free_args(args);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_copy);
		free_args(args);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			print_error(program_name, cmd_count, args[0]);
			free(cmd_copy);
			free_args(args);
			exit(2);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(cmd_copy);
	free_args(args);
	return (1);
}
