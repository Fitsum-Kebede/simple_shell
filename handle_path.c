#include "shell.h"

/**
 * gen - obtains the required env variable
 * @name: the env variable's name
 * @environ: variables in env
 * Return: the line containing the env parameter
*/

char *gen(char *name, char **environ)
{
	int a, b, k;

	k = _sle(name);
	for (a = 0; environ[a]; a++)
	{
		for (b = 0; environ[a][b] == name[b]; b++)
		{
		}
		if (b == k && environ[a][b] == '=')
			return (environ[a]);

	}
	return (NULL);
}

/**
 * gpath - the variable PATH is obtained
 * @environ: enviroment factor
 * @input: input/command passe by the user
 * Return: the PATH variable that was divided
*/

char *gpath(char **environ, char *input)
{
	char **path = NULL, *inp;
	unsigned int input_len, path_len, a, b, k;
	struct stat st;

	path = split_line(gen("PATH", environ), "=:");
	input_len = _sle(input);

	for (a = 1; path[a]; a++)
	{
		path_len = _sle(path[a]);
		inp = malloc(sizeof(char) * (path_len + input_len + 2));
		if (!inp)
		{
			write(2, "Unable to allocate memory", 25);
			exit(1);
		}

		for (b = 0; path[a][b]; b++)
			inp[b] = path[a][b];

		inp[b++] = '/';

		for (k = 0; input[k]; k++)
			inp[b + k] = input[k];

		inp[b + k] = '\0';

		if (stat(inp, &st) == 0)
		{
			arrfix(path);
			return (inp);
		}
		free(inp);
	}
	arrfix(path);

	return (NULL);
}
