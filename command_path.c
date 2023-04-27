#include "main.h"
/**
 * command_path - function
 * @cmd: char
 * Return: NULL
 */
char *command_path(char *cmd)
{
	int i = 0;
	char *path = strdup(_getenv("PATH")), *new_path = NULL, *token, *a_path[100];
	struct stat buffer;

	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':')
	{
	if (stat(cmd, &buffer) == 0)
		return (strdup(cmd));/*Copy the words into the array*/
	token = strtok(path, ":");
	while (token != NULL)
	{
	a_path[i] = token;
	i++;
	token = strtok(NULL, ":");
	}
	a_path[i] = NULL;/*Ends the array_path*/
	for (i = 0; a_path[i]; i++;
	{
		strcpy(new_path, a_path[i]);
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
