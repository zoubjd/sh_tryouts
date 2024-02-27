#include "shell.h"

/**
 * read_line - check the code
 * description: the function read the user's line/command
 * Return:  the line.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;
	int cmp = 0;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#badrzou$ ", 10);
	}
	n = getline(&line, &len, stdin);
	if (n < 0)
	{
		free(line);
		return (NULL);
	}

	cmp = strcmp(line, "exit\n");
	if (cmp == 0)
	{
		exit(0);
	}
	return (line);
}
