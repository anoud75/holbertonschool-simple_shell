#include "shell.h"

/**
 * trim_spaces - Removes leading and trailing spaces from a string
 * @str: The string to trim
 *
 * Return: Pointer to the trimmed string
 */
char *trim_spaces(char *str)
{
	char *end;

	if (str == NULL)
		return (NULL);

	/* Trim leading spaces */
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;

	/* If all spaces, return empty string */
	if (*str == '\0')
		return (str);

	/* Trim trailing spaces */
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r'))
		end--;

	/* Write new null terminator */
	*(end + 1) = '\0';

	return (str);
}
