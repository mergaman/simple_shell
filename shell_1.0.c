#include "shell.h"
#define MAX_ARGS 10
extern char **environ;

/**
 * env_builtin - Print the current environment
 *
 * Return: Always 0
 */
int env_builtin(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * parse_command- Parse the command string into arguments
 *
 * @command: The command string to parse
 * @args: An array of strings to store the parsed argument
 *
 * Return: none
 */

void parse_command(char *command, char **args)
{
	int len, i = 0;
	char *token;

	len = _strlen(command);
	if (len > 0 && command[len - 1] == '\n')
		command[len - 1] = '\0';
	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}

/**
 * find_command - Search for the command in the directories listed in PATH
 *
 * @args: An array of strings containing the command and its arguments
 *
 * Return: none
 */

int find_command(char **args)
{
	char *path, *path_token, *path_copy;
	int command_found = 0;

	if (args[0][0] == '/')
	{
		if (access(args[0], X_OK) == 0)
			command_found = 1;
	}
	else
	{
		path = getenv("PATH");
		path_copy = strdup(path);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			char *command_path = malloc(strlen(path_token) + strlen(args[0]) + 2);

			sprintf(command_path, "%s/%s", path_token, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				args[0] = command_path;
				command_found = 1;
				break;
			}
			else
				free(command_path);
			path_token = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (command_found);
}
/**
 * execute_command - Execute the command
 *
 * @args: An array of strings containing the command and its arguments
 *
 * Return: none
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		printf("Error: Failed to create child process\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("%s: Command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);
}
/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[MAX_ARGS + 1];
	int command_found;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &command_size, stdin) == -1)
		{
			printf("\n");
			break;
		}
		parse_command(command, args);
		if (_strcmp(args[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		if (_strcmp(args[0], "env") == 0)
			env_builtin();
		else
		{
		command_found = find_command(args);
		if (command_found)
			execute_command(args);
		else
			printf("%s: Command not found\n", args[0]);
		}
	}
	free(command);
	return (0);
}

