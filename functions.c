#include "shell.h"

/**
 * _sle - determines how long a string is
 * @ring: counting a string
 * Return: the string's character count
*/

int _sle(char *ring)
{
	int a;

	/* loop through the string until reaching the null terminat */
	for (a = 0; ring[a]; a++)
	{
	}

	return (a);
}

/**
 * _su - copies the given string.
 * @ring: a strng to be copied
 * Return: a reference to a copy of the provided string
*/

char *_su(char *ring)
{
	char *dup;
	int a;

	/* loop through the duplicated string */
	for (a = 0; ring[a]; a++)
	{
	}
	dup = malloc((sizeof(char) * a) + 1);
	if (!dup)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}
	for (a = 0; ring[a]; a++)
	{
		dup[a] = ring[a];
	}
	dup[a] = '\0';

	return (dup);
}

/**
 * split_line - separates a string based on delim into a 2d array
 * @ring: split a string
 * @delim: delimiter to consider while splitting the string.
 * Return: a split-up double pointer of characters with the string.
*/

char **split_line(char *ring, char *delim)
{
	int a, b, chars, lns = 1;
	char **splitted, *token, *strdup;

	strdup = _su(ring);

	for (a = 0; strdup[a]; a++)
		if (strdup[a] == delim[0] || strdup[a] == delim[1])
			lns++;

	splitted = malloc((lns + 1) * sizeof(char *));
	if (!splitted)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}
	token = strtok(strdup, delim);
	b = 0;
	while (token)
	{
		chars = _sle(token);
		splitted[b] = malloc((chars + 1) * sizeof(char));
		if (!splitted)
		{
			write(2, "Unable to allocate memory", 25);
			for (; b != 0 ; b--)
				free(splitted[b - 1]);
			free(splitted);
			exit(1);
			}
		for (a = 0; a < chars; a++)
		{
			splitted[b][a] = token[a];
		}
		splitted[b][a] = '\0';
		b++;
		token = strtok(0, delim);
	}
	splitted[b] = NULL;
	free(strdup);
	return (splitted);
}

/**
 * _sc - two arrays are compared
 * @origin: the first array
 * @su: the second array
 * Return: 1 if it is similar0, 0 if it is not
*/

int _sc(char *origin, char *su)
{
	int a;

	for (a = 0; origin[a] && su[a]; a++)
	{
		if (origin[a] != su[a])
			break;
	}

	if (a == _sle(origin) && a == _sle(su))
		return (1);
	else
		return (0);
}

/**
 * nums - determines the number of digits.
 * @n: number to evaluate
 * Return: Quantity of digits
*/

char *nums(int n)
{
	int a = 0, b, number = n;
	char *strnumber;

	for (a = 0; n != 0; a++)
	{
		n = n / 10;
	}

	strnumber = malloc(sizeof(char) * (a + 1));

	for (b = 1; b <= a; b++)
	{
		strnumber[a - b] = (number % 10) + '0';
		number = number / 10;
	}
	strnumber[a] = '\0';
	return (strnumber);
}
