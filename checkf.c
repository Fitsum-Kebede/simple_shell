#include "main.h"

/**
 *_checkf - function to be checked
 * @arg: string to check
 * Return: NULL if false or attach the needed path
*/

char *_checkf(char *arg)
{
	DIR *dir = opendir("/bin/");
	char  *temp * cat;
	struct dirent *entity;

	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);

	while (entity != NULL)
	{
		temp = entity->d_name;
		if (_strcmp(temp, arg) == 0)
		{
			cats = _strcat("/bin/", arg);
			closedir(dir);
			return (cat);
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
