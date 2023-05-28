#include "monty.h"

/**
 * allocate_memory - allocate memory for buffer
 * @filename: file for which to create buffer
 *
 * Return: pointer to buffer
*/

char *allocate_memory(char *filename)
{
	char *buf = malloc(sizeof(char) * MAX_LINE_LEN);

	if (!buf)
	{
		fprintf(stderr, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buf);
}
