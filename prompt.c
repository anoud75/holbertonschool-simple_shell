#include "shell.h"

/**
 * display_prompt - Displays the shell prompt
 *
 * Return: void
 */
void display_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, 2);
	fflush(stdout);
}
