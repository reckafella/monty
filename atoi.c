#include "monty.h"

/**
 * is_numeric - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */

int is_numeric(const char *str)
{
	if (!str || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}

	return (1);
}
