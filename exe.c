#include "main.h"

/**
 * _execute - system is executed with fork
 * @args: array of strings
 * @vn: environment variables
 *
 * Return: void
*/

void _execute(char **args, char *vn[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: fork issue");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, vn) == -1)
			perror("$ : no such file or directory\n");
	}
	else
	{
		wait(&sta);
	}
}
