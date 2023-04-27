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
int env_builtin(void);
char *_getline(void);

size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);

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

/**
 * _strcmp - Compare two strings
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
#endif
