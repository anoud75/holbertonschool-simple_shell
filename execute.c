#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @command: The command line to execute
 * @program_name: Name of the shell program (for error messages)
 * @cmd_count: Current command count
 * @last_status: Pointer to store last exit status
 *
 * Return: 1 to continue execution, -1 to exit
 */
int execute_command(char *command, char *program_name, int cmd_count, int *last_status)
{
	pid_t pid;
	int status, builtin_result;
	char **args = NULL;
	char *cmd_copy = NULL;
	char *cmd_path = NULL;

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

	/* Check if it's a built-in command */
	builtin_result = handle_builtin(args, *last_status);
	if (builtin_result == -1)
	{
		free(cmd_copy);
		free_args(args);
		return (-1);
	}
	if (builtin_result == 1)
	{
		free(cmd_copy);
		free_args(args);
		return (1);
	}

	/* Not a built-in, find command in PATH */
	cmd_path = find_command_in_path(args[0]);
	
	if (cmd_path == NULL)
	{
		print_error(program_name, cmd_count, args[0]);
		*last_status = 127; /* Command not found */
		free(cmd_copy);
		free_args(args);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		free(cmd_copy);
		free_args(args);
		return (1);
	}

	if (pid == 0)
	{
		args[0] = cmd_path;
		if (execve(cmd_path, args, environ) == -1)
		{
			print_error(program_name, cmd_count, args[0]);
			free(cmd_path);
			free(cmd_copy);
			free_args(args);
			exit(127);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		/* Get the exit status of the child process */
		if (WIFEXITED(status))
			*last_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			*last_status = 128 + WTERMSIG(status);
	}

	free(cmd_path);
	free(cmd_copy);
	free_args(args);
	return (1);
}
