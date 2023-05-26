#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* simple_shell.c */

int ex(char *inp, char **argum, char *va);
int cmdshell(char *, char **, int, char **, char **, int *);
void no_file(int lns, char *div, char **va);
char *li_m(size_t size);

/* the string handler functions */

int _sle(char *ring);
char *_su(char *ring);
char **split_line(char *ring, char *delim);
int _sc(char *origin, char *su);
char *nums(int n);

/* the path handler functions */

char *gen(char *name, char **environ);
char *gpath(char **environ, char *input);

/* the memory handler functions */
int arrfix(char **ring);

#endif

