#include "shell.h"

/**
 * executefree - Execute a command free the current
 * @arg: command to free
 */
void executefree(char **arg)
{
	int i = 0;

	if (arg == NULL)
		return;

	while (arg[i] != NULL)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
