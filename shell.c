#include "main.h"

int main (int __attribute__((unused)) argc, char *argv[])
{
    char *line = NULL;
    int checker; 
    ssize_t linelen = 0;
	size_t linecap = 0;

    name = argv[0];

    while (1)
    {
        printf("$ ");

        line = malloc(linecap * sizeof(char));
        if (line == NULL)
        {
            perror("Failed to allocate memory");
            exit (-1);
        }

        linelen = getline(&line, &linecap, stdin);

        if (linelen == -1)
        {
            /* Handle EOF */
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            /* Handle error */
            perror("getline");
            exit(-1);
        }

        if (linelen > 0 && line[linelen -1] == '\n')
            line[linelen - 1] = '\0';

        checker = command_read(line, strlen(line));

        if (checker == 2)
            break;
        
    }
    free(line);
    return (0);
}

int command_read(char *s, size_t __attribute__((unused)) characters)
{
    char *token = NULL;
    char *path_array[100];
    int i = 0;

    if (strcmp(s, "exit") == 0)
        return (2);

    if (strcmp(s, "env") == 0)
        return (_printenv());

    token = strtok(s, " ");
    while (token)
    {
        path_array[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    path_array[i] = NULL;

    return (execute(path_array));
}

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
        write(2, strcat(cmd, ": Not found\n"), strlen(cmd) + 12);
		return (3);
        /*
        write(2, name, strlen(name));        
        write(2, ": ", 2);
        write(2, cmd, strlen(cmd));
        write(2, ": not found\n", 12);
        return (3);
        */
    }

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Failed to create a child proccess");
        exit(-1);
    }
    else if (pid == 0)
    {
        execve(execute_path, cmd_array, environ);
        perror("Error");
        exit(-1);
    }
    else 
    {
        wait(&status);
    }
    free(execute_path);
    return (0);
}
