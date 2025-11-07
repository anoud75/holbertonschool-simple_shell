#include "shell.h"

/**
 * print_error - Prints an error message
 * @program_name: Name of the shell program
 * @cmd_number: Command number (for error tracking)
 * @command: The command that failed
 *
 * Return: void
 */
void print_error(char *program_name, int cmd_number, char *command)
{
	char num_str[12];

	sprintf(num_str, "%d", cmd_number);

	write(STDERR_FILENO, program_name, strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num_str, strlen(num_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}
