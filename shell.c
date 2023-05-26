#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * ex - runs the specified application
 * @inp: input to excute
 * @argum: argument to pass
 * @va: the name of the program
 * Return: -1 if it breaks, 0 if it doesn't break
*/

int ex(char *inp, char **argum, char *va)
{
	int ch;

	/* create a new process by duplicating the calling process */
	ch = fork();

	/* if the process is the child and fails to execute the input */
	if (ch != 0)
		wait(NULL);

	if (ch == 0 && execve(inp, argum, NULL) == -1)
	{
		write(2, va, _sle(va));
		perror(": ");
		return (errno);
	}

	return (0);
}

/**
 * main - Entry point
 * @ac: passed amount of arg
 * @va: passed arg
 * @env: Enviroment variables
 * Return: 0 if (success)
*/

int main(int ac __attribute__((unused)), char **va, char **env)
{
	char *line, **splitt;
	size_t size = 32;
	int *error_value = malloc(sizeof(int)), read, error, lns = 1;

	/* initialize the error value to 0 */
	*error_value = 0;
	line = li_m(size);
	if (!line)
		exit(-1);
	while (1)
	{
		if (isatty(0) == 1)
			write(1, "smpl_shel# ", 11);
		read = getline(&line, &size, stdin);
		if (read == -1)
			break;
		if (read == 1)
			continue;
		line[read - 1] = ' ';
		splitt = split_line(line, " ");
		if (!*splitt)
		{
			free(splitt);
			continue;
		}
		switch (cmdshell(line, splitt, lns, env, va, error_value))
		{
			case 0:
				error = *error_value;
				free(error_value);
				exit(error);
			case 1:
				continue;
		}
		lns++;
	}
	free(line);
	error = *error_value;
	free(error_value);
	return (error);
}


/**
 * cmdshell - simpleshell
 * @line: input provided by the user
 * @div: input
 * @lns: the amt
 * @env: enviroment variable
 * @va: argum
 * @err: error pointer
 * Return: 10 success, 0  exit, 1 continue, -1 if return-1
*/

int cmdshell(char *line, char **div, int lns, char **env, char **va, int *err)
{
	char *inp;
	int a;
	struct stat st;

	if (_sc(div[0], "exit"))
	{
		arrfix(div);
		free(line);
		return (0);
	}
	if (_sc(div[0], "env"))
	{
		for (a = 0; env[a]; a++)
		{
			write(1, env[a], _sle(env[a]));
			write(1, "\n", 1);
		}
		return (arrfix(div));
	}
	if (stat(div[0], &st) == 0)
	{
		*err = ex(div[0], div, va[0]);
		return (arrfix(div));
	}
	inp = gpath(env, div[0]);
	if (!inp)
	{
		*err = 127;
		no_file(lns, div[0], va);
	}
	else if (ex(inp, div, va[0]) == -1)
	{
		perror(": ");
		*err = errno;
		return (0);
	}
	arrfix(div);
	free(inp);
	return (10);
}

/**
 * no_file - ouput the err message
 * @lns: lines
 * @div: proccessed input
 * @va: amnt of lines
*/

void no_file(int lns, char *div, char **va)
{
	char *strlines = nums(lns);

	write(2, va[0], _sle(va[0]));
	write(2, ": ", 2);
	write(2, strlines, _sle(strlines));
	write(2, ": ", 2);
	write(2, div, _sle(div));
	write(2, ": not found\n", 12);
	free(strlines);
}

/**
 * li_m - the input variable is made
 * @size: Size of the malloc
 * Return: input
 */

char *li_m(size_t size)
{
	char *input;

	input = (malloc(sizeof(char) * size));
	if (!input)
		write(2, "Unable to allocate memory", 25);

	return (input);
}

