#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define END_OF_FILE -2
#define EXIT -3

/*string functions*/
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accept);

extern char **environ;
char *name;
int shell_exit(char **args, char **infront);
int shell_env(char **args, char __attribute__((__unused__)) **infront);
int shell_setenv(char **args, char __attribute__((__unused__)) **infront);
int shell_unsetenv(char **args, char __attribute__((__unused__)) **infront);
int shell_cd(char **args, char __attribute__((__unused__)) **infront);
int shell_alias(char **args, char __attribute__((__unused__)) **infront);
int shell_help(char **args, char __attribute__((__unused__)) **infront);

void free_alias_list(alias_t *head);
void free_list(list_t *head);

alias_t *aliases;
void free_args(char **args, char **infront);
void free_env(void);

int create_error(char **args, int err);
#endif /* _SHELL_H_ */
