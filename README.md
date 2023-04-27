# Holberton-Simple-Shell

A simple implementation of a shell written in C for the Holberton School curriculum. This shell provides basic features such as command execution, path searching, environment variable expansion, and built-in commands (exit and env).

## Installation
​​To install the Holberton Simple Shell, you can clone this repository by running the following command:

```
git clone https://github.com/issaevis/holbertonschool-simple_shell.git

```

After cloning the repository, navigate to the directory containing the cloned files and compile the shell using the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```


## Usage
​
To start the Holberton Simple Shell, simply run the hsh executable:
```
./hsh
```
The shell will then display a command prompt, where you can enter commands:
```
$ ls -l
```
The Holberton Simple Shell supports both built-in and external commands, which are described in more detail below.

To exit the shell, simply enter the exit command:

```
$ exit
```

## Features

The Holberton Simple Shell includes the following features:

- Command execution
- Environment variable management
- Directory navigation
- Command history
- Signal handling
- Interactive and non-interactive modes
​
## Built in commands

​The Holberton Simple Shell includes several       built-in commands that are executed internally, without invoking an external program. These commands include:

    'cd': Change the current working directory.
    'env': Print the environment variables.
    'exit': Exit the shell.

To learn more about how to use these commands, type help followed by the command name.

## Function Descriptions

This table describes the functions in the order they appear in the source code:

| File | Function | Description  |
| :---:   | :---: | :---: |
| 'main.c' | 'main' | Entry point of the shell |
| 'main.c' | 'command_read' | Function to read commands |
| 'main.c' | 'execute' | Function to execute a command 
| 'path.c' | 'command_path' | Function to find the path of a command |
| 'environment.c' | '_getenv' | Function to get an environment variable |
| 'environment.c' | '_printenv' | Function to print all environment variables |

​
## Contributors

This shell was written by: Klajdi Dhana, Evis Topollaj, Patrik Shalsi and Akil Kabellari


## Happy coding!


