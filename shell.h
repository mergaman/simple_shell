#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

void prompt(char **av, char **env);
void parse_command(char *command, char **args);
int find_command(char **args);
void execute_command(char **args);


size_t _strlen(const char *s);
/**
 * _strlen - Calculate the length of a string
 *
 * @s: The string to calculate the length of
 *
 * Return: The length of the string
 */

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

#endif
