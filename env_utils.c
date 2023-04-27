#include "main.h"
/**
 * _printenv - print env
 * Return: Value zero.
 */

int _printenv(void)
{
	int i = 0;
	char **curr = environ;

	while (curr[i] != NULL)
	{
		write(STDOUT_FILENO, curr[i], strlen(curr[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
/**
 * _getenv - getting env
 * @name: parameter name
 * Return: NULL
 */
char *_getenv(char *name)
{
	int len = strlen(name);
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			return (&environ[i][len]);
		}
	i++;
	}
	return (NULL);
}
