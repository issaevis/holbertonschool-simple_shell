#include "main.h"
/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument values
 *
 * Return: Always 0 (Success)
 */

int main (int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	int checker; 
	ssize_t linelen = 0;
	size_t linecap = 0;

	name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		linelen = getline(&line, &linecap, stdin);

		if (linelen == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				printf("\n");
			break;
		}

		if (linelen > 0 && line[linelen -1] == '\n')
			line[linelen - 1] = '\0';
		if (*line == '\0')
			continue;
		checker = command_read(line, linelen);

		if (checker == 2)
			break;
		else if (checker == 1)
			return (2);
	}
	free(line);
	return (0);
}

/**
 * command_read - function that reads commands
 *
 * @s: command
 * @characters: characters of the command
 *
 * Return: return value
 */

int command_read(char *s, size_t __attribute__((unused)) characters)
{
	char *token = NULL;
	char *path_array[100];
	int i = 0;

	if (strcmp(s, "exit") == 0)
		return (2);

	if (strcmp(s, "env") == 0)
		return (_printenv());
	path_array[0] = NULL;
	token = strtok(s, " ");
	if (token == NULL)
		return (0);
	while (token)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	path_array[i] = NULL;
	if (strlen(path_array[0]) == 0)
	{
		free(path_array[0]);
		path_array[0] = NULL;
	}
	return (execute(path_array));
}

/**
 * execute - function to execute a command
 *
 * @cmd_array: array that contains the command
 *
 * Return: return value 0
 */

int execute(char *cmd_array[])
{
	pid_t pid;
	char *execute_path = NULL;
	char *cmd = NULL;
	int status;

	cmd = cmd_array[0];
	execute_path = command_path(cmd);

	if (execute_path == NULL)
	{
        write(2, name, strlen(name));        
        write(2, ": 1: \n", 5);
        write(2, cmd, strlen(cmd));
        write(2, ": not found\n", 12);
	free(execute_path);
	free(cmd);
        exit (127);
    }

	pid = fork();

	if (pid < 0)
	{
        perror("Failed to create a child proccess");
        exit(-1);
	}
	else if (pid == 0)
	{
		if (environ)
		{
			execve(execute_path, cmd_array, environ);
			perror("Error");
			exit(1);
		}
		else
			execve(execute_path, cmd_array, NULL);
	}
	else 
		wait(&status);

	free(execute_path);
	return (0);
}
