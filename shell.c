#include "main.h"

/**
 * input - a function that allows the user to input prompt
 * Return: noting
 */

#define MAX_COMMAND 15

void input(char **ca, char **vn)
{
int nu = 0, mb, sta;
size_t m = 0;
ssize_t st_ch;
char *arg[MAX_COMMAND], *value = NULL;
pid_t c_pid;

while (1)
{
if (isatty(STDIN_FILENO))
printf("DonebyF&V# ");
st_ch = getline(&value, &m, stdin);
if (st_ch == -1)
{
free(value);
exit(EXIT_FAILURE);
}
while (value[nu])
{
if (value[nu] == '\n')
value[nu] = 0;
nu++;
}
mb = 0;
arg[mb] = strtok(value, " ");
while (arg[mb])
arg[++mb] = strtok(NULL, " ");
c_pid = fork();
if (c_pid == -1)
{
free(value);
exit(EXIT_FAILURE);
}
if (c_pid == 0)
{
if (execve(arg[0], arg, vn) == -1)
printf("%s: No such file or directory", ca[0]);
}
else
wait(&sta);
}
}
