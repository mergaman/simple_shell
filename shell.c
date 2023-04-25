#include "shell.h"
/**
 * main - Display a prompt and wait for the user to type a command.
 * A command line always ends with a new line
 *
 * return - return (1) sucess
 */
int main()
{
	char *command = NULL;
	size_t command_size = 0;
	int status,len;
	pid_t pid;
	char *args[2];

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&command, &command_size, stdin) == -1)
		{
			printf("\n");
			break;
		}
		len = strlen(command);
		if (len > 0 && command[len-1] == '\n')
		{
			command[len-1] = '\0';
		}
		pid = fork();
		if (pid == -1)
		{
			printf("Error: Failed to create child process\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) {
		args[0] = command;
		args[1] = NULL;
		if(execve(command, args, NULL) == -1)
		{
			printf("%s: Command not found\n", command);
			exit(EXIT_FAILURE);
		}	}
		else
			waitpid(pid, &status, 0);
		}
	free(command);
	return 0;
}

