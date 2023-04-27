#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * _getline - reads an entire line from stream,
 *
 * Return : return null
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos = 0, buffer_size = 0;
	char *line = NULL;
	int line_pos = 0, line_size = 0, read_size = 0;

	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (read_size == -1)
				exit(EXIT_FAILURE);
			buffer_size = read_size, buffer_pos = 0;
			if (buffer_size == 0)
				break;
		}
		while (buffer_pos < buffer_size)
		{
			if (buffer[buffer_pos] == '\n')
			{
				line[line_pos] = '\0';
				return (line);		}
			else
			{
				if (line_pos >= line_size)
				{
					line_size += BUFFER_SIZE;
					line = realloc(line, line_size);
					if (line == NULL)
						exit(EXIT_FAILURE);	}
				line[line_pos++] = buffer[buffer_pos++];	}	}	}
	if (line_pos > 0)
	{
		line[line_pos] = '\0';
		return (line);
	}
	return (NULL);	}
