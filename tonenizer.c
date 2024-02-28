#include "shell.h"
/**
 * tokens - a list of tokens separated by spaces.
 * @line: the line number of the token.
 * Return: the number of tokens separated.
 */
char **tokens(char *line)
{
	char *token = NULL, *delim = " \t\n", **command = NULL, *ptr = line;
	int i = 0, j, num_tokens = 1;

	if (line == NULL)
		return (NULL);

	while (*ptr != '\0')
	{
		if (strchr(delim, *ptr) != NULL)
		{
			num_tokens++;
		}
		ptr++;
	}

	command = malloc((num_tokens + 1) * sizeof(char *));
	if (command == NULL)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, delim);
	if (token == NULL)
	{
		free(line);
		free(command);
		return (NULL); /* no command entered */
	}
	command[0] = _strdup(token);
	if (command[0] == NULL)
	{
		free(command);
		free(line);
		return (NULL);
	}

	for (i = 1; i < num_tokens; i++)
	{
		token = strtok(NULL, delim);
		if (token != NULL)
		{
			command[i] = _strdup(token);
			if (command[i] == NULL)
			{
				free(line);
				for (j = 0; j < i; j++)
				{
					free(command[j]);
				}
				free(command);
				return (NULL);
			}
		}
		else
		{
			command[i] = NULL; /* initialize token to NULL*/
		}
	}
	command[num_tokens] = NULL;

	free(line);
	return (command);
}
