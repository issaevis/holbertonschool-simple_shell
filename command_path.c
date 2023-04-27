#include "main.h"

char *command_path(char *cmd)
{
    int i = 0;
    char *path = strdup(_getenv("PATH"));
    char *new_path = NULL, *token = strtok(path, ":");
    struct stat buffer;
    char *array_path[100];

    new_path = malloc(sizeof(char) * 100);
    if (path == NULL)
	    if (stat(cmd, &buffer) == 0)
		    return (_strdup(cmd));
    while (token != NULL)
    {
        array_path[i] = token;
        i++;
        token = strtok(NULL, ":");
    }
    array_path[i] = NULL;/*Ends the array_path*/
    for (i = 0; array_path[i]; i++)
	{
		strcpy(new_path, array_path[i]);
		strcat(new_path, "/");
		strcat(new_path, cmd);
		strcat(new_path, "\0");
		if (stat(new_path, &buffer) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);
	if (stat(cmd, &buffer) == 0)
		return (strdup(cmd));
	return (NULL);
}
