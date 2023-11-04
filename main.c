#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	size_t bytes_getline = 0;
	char *tokenized = NULL;
	size_t cmd_buf_size = 0;
	char *cmd_entered = NULL;
	char **arguments = malloc(10 * sizeof(char *));
	int j = 0;
	//display_prompt(void);
	//bytes_getline = getline(&cmd, &cmd_buf_size, stdin);
	bytes_getline = getline(&cmd_entered, &cmd_buf_size, stdin);
	tokenized = strtok(cmd_entered, " ");
	while (tokenized != NULL)
	{
		arguments[j] = malloc(sizeof(char) * strlen(tokenized) + 1);
		strcpy(arguments[j], tokenized);
		j++;
		tokenized = strtok(NULL," ");
	}
	arguments[j] = NULL;
	int k = 0;

	for ( k = 0; k < j; k++)
	{
		printf("%d: %s\n", k, arguments[k]);
	}
	printf("The number of chars is %ld\n", bytes_getline);
	if (cmd_entered != NULL)
	{
		free(cmd_entered);
	}
	for (int l = 0; l < j; l++)
	{
		if (arguments[l] != NULL)
		{
			free(arguments[j]);
		}
	}
	free(arguments);
}
