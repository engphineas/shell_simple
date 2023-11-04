#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

void our_display_prompt(void);
void our_print(const char *string);
void read_cmd(char *cmd, size_t cmd_size);
void execute_cmd(const char *cmd);
char *placement(char *path_env, char *arguments);
char *get_path(char *arguments);
int built_in_cmd(char **arguments);

#endif 
