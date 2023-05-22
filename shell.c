#include "main.h"

/**
 * input - a function that allows the user to input prompt
 * @value: to store the input string
 * @arg: To store command and arguments
 * Return: noting
 */

#define MAX_COMMAND 15

void input(char **ca, char **vn)
{
char *value = NULL;
int nu;
int mb;
int sta;
size_t m = 0;
ssize_t st_ch;
char *arg[MAX_COMMAND];
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
nu = 0;
while (value[nu])
{
if (value[nu] == '\n')
value[nu] = 0;
nu++;
}
mb = 0;
arg[mb] = strtok(value, " ");
while (arg[mb])
arg[++mb] = strtok(NULL, "");
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

