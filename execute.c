#include "shell.h"

/**
 * my_execute - check the code
 * description: the function executes the commands
 * @command: the command to be executed
 * @argv: the command line arguments
 * @dex: the status
 * Return: Always 0.
 */

int my_execute(char **command, char **argv, __attribute__ ((unused)) int dex)
{
	pid_t child_pid;
	int status;
	char **env = environ;
	int cmp = 0;
	int comp = 0;

	cmp = strcmp(command[0], "exit");
	if (cmp == 0)
	{
		executefree(command);
		exit(127);
	}
	comp = strcmp(command[0], "env");
	if (comp == 0)
		print_env();

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (child_pid == 0)
	{
		execve(command[0], command, env);
		perror(argv[0]);
		executefree(command);
		_exit(EXIT_FAILURE);
	}
	waitpid(child_pid, &status, 0);

	executefree(command);
	return (WEXITSTATUS(status));
}

/**
 * print_env - check the code
 * description: the function prints the envirenoment
 * @command: the command to be executed
 * @argv: the command line arguments
 * @dex: the status
 * Return: Always 0.
 */

int print_env(void) {
int i = 0;
while(environ[i]) {
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(1, "\n", 1);
i++;
}
return 0;
}
