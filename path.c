#include "shell.h"

/**
 * get_path - Get the PATH environment variable
 * @command: The command to find (unused here)
 *
 * Return: Pointer to PATH string, or NULL if not found
 */
char *get_path(char *command)
{
	int i = 0;

	(void)command;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * find_command_in_path - Find the full path of a command
 * @command: The command to find
 *
 * Return: Full path to command, or NULL if not found
 */
char *find_command_in_path(char *command)
{
	char *path_env = NULL;
	char *path_copy = NULL;
	char *dir = NULL;
	char *full_path = NULL;
	struct stat st;

	if (command == NULL)
		return (NULL);

	/* If command contains '/', it's already a path */
	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path_env = get_path(command);
	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
