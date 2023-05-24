#include "main.h"

/**
 * _checkp - checks if string has path
 * @arg: carry check
 * Return: 1 if path is found or 0 if false
*/
int _checkp(char *arg)
{
	char *cmd = "/bin/", *ptr, *n;
	int i = 0, p = 0;

	ptr = malloc(sizeof(char) * 60);
	if (ptr == NULL)
		return (0);
	while (cmd[i] != '/0')
	{
		if (cmd[i] != arg[i])
		{
			free(ptr);
			return (0);
		}
		i++;
	}
	while (arg[i] != '\0')
	{
		ptr[p] = arg[i];
		p++;
		i++;
	}
	ptr[p] = '\0';
	n = checkf(ptr);
	if (n != NULL)
	{
		free(ptr);
		return (1);
	}
	return (0);
}
