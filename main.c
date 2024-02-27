#include "shell.h"

/**
 * main - main function of the simple shell
 * @argc: void.
 * @argv: string argument to shell command.
 * Return: always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, index = 0;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}
		else
		{
			index++;
			command = tokens(line);
			if (command == NULL)
			{
				continue;
			}
		}
		status = my_execute(command, argv, index);
	}
	return (0);
}
