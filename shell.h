#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker(char **cmd, char *buf);
void prompt_user(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char **path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);
void print_env(void);

/* string handlers */
int strcmp(const char *s1, const char *s2);
size_t strlen(const char *s);
int strncmp(const char *s1, const char *s2, size_t n);
char *strdup(const char *s);
char *strchr(const char *s, int c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);

/* Structs */
struct builtin
{
	char *env;
	char *exit;
};

struct info
{
	int final_exit;
	int ln_count;
};

struct flags
{
	bool interactive;
}flags;

/* Builtin functions */
int set_env(char **command);
int unset_env(char **command);
int cd_builtin(char **command);


#endif /* SHELL_H */

