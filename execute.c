#include "shell.h"

/**
 * my_execute - check the code
 * description: the function executes the commands
 * @command: the command to be executed
 * @argv: the command line arguments
 * @dex: the status
 * Return: Always 0.
 */

int my_execute(char **command, char **argv, int dex)
{
	pid_t child_pid;
	int status;
	char **env = environ;
	char *fullcmd;

	if (command == NULL || command[0] == NULL)
	{
		return (0);
	}
	fullcmd = make_path(command[0]);
	if (fullcmd == NULL)
	{
		print_error(argv[0], command[0], dex);
		executefree(command);
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(fullcmd, command, env) == -1)
		{
			free(fullcmd);
			executefree(command);
			_exit(EXIT_FAILURE);
		}
	}
	waitpid(child_pid, &status, 0);
	executefree(command);
	free(fullcmd);

	return (WEXITSTATUS(status));
}
