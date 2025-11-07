#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void display_prompt(void);
char *read_line(void);
int execute_command(char *command, char *program_name, int cmd_count);
void print_error(char *program_name, int cmd_number, char *command);
char *trim_spaces(char *str);

#endif
