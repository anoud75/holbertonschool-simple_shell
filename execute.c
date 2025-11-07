#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute (full path)
 * @program_name: Name of the shell program (for error messages)
 * @cmd_count: Current command count
 *
 * Return: 1 to continue execution, 0 to exit
 */
int execute_command(char *command, char *program_name, int cmd_count)
{
	pid_t pid;
	int status;
	char *args[2];
	struct stat st;

	if (command == NULL || command[0] == '\0')
		return (1);

	if (stat(command, &st) == -1)
	{
		print_error(program_name, cmd_count, command);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;

		if (execve(command, args, environ) == -1)
		{
			print_error(program_name, cmd_count, command);
			exit(2);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
