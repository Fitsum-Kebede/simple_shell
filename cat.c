#include "shell.h"
/**
 * string_nconcat - a function that concat two strings
 * @s1: string one
 * @s2: string two
 * @n: an unsigned int
 * Return: two strings concatenated
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, i;
	char *ptr, *ret;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	for (len1 = 0, ptr = s1; *ptr; ptr++)
		len1++;
	for (len2 = 0, ptr = s2; *ptr; ptr++)
		len2++;
	if (n > len2)
		n = len2;

	ret = malloc((len1 + n + 1) * sizeof(char));
	if (!ret)
		return (0);

	ptr = ret;
	while (*s1)
		*ptr++ = *s1++;
	i = 0;
	while (i < n)
	{
		*ptr++ = s2[i++];
	}
	*ptr = 0;

	return (ret);
}
/**
 * path_finder - finds the path
 * @env: enviroment
 * Return: env
 */
char *path_finder(char **env)
{
	int i, j;
	char *path = "PATH=";

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; path[j] == env[i][j]; j++)
		{
		}
		if (j == 4)
		{
			return (env[i]);
		}
	}
	return (env[i]);
}
