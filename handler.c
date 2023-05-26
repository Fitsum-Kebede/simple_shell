#include "shell.h"

/**
 * arrfix - A double pointer is cleared
 * @ring: Double pointer to be cleaned
 * Return: 1
 */

int arrfix(char **ring)
{
	int a;

	for (a = 0; ring[a]; a++)
	{
		free(ring[a]);
	}
	free(ring);

	return (1);
}

