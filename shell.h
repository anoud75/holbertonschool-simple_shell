#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* External variable */
extern char **environ;

/* Function prototypes */
void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);

#endif /* SHELL_H */
