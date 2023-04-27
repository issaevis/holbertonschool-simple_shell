#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *name;

/* The prototypes of the string functions */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t count);

char *command_path(char *cmd);

int _printenv(void);
char *_getenv(char *name);

int command_read(char *s, size_t __attribute__((unused)) characters);
int execute(char *cmd_array[]);

#endif
