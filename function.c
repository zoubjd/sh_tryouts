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

char* _itoa(int n)
{
	char buf[20];
	int i = 0;

	if (n == 0)
	{
		buf[i++] = '0';
	}
	else
	{
		while (n != 0)
		{
			buf[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buf[i] = '\0';
	
	reverse_string(buf, i);
	return (_strdup(buf));
}

void reverse_string(char *buf, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = buf[start];
		buf[start] = buf[end];
		buf[end] = tmp;
		start++;
		end--;
	}
}

void print_error(char *name, char *command, int index)
{
	char *i = _itoa(index), message[] = ": not found\n";

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));

	free(i);
}
