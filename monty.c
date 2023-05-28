#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

char *push_arg;

/**
 * main - entry point
 * @argc: number of arguments passed to the program
 * @argv: argument vector
 *
 * Return: 0 always
*/
int main(int argc, char **argv)
{
	FILE *fd;
	char *line = NULL, *opcode;
	size_t line_size = 32, line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
		usage_error();

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		file_io_error(argv[1]);

	while ((getline(&line, &line_size, fd)) != (-1))
	{
		if (line == NULL || line[0] == '#' || line[0] == '\n')
		{
			line_number++;
			continue;
		}
		line[strcspn(line, "#")] = '\0';
		line[strcspn(line, "\n")] = '\0';

		opcode = strtok(line, " ");
		if (strcmp(opcode, "push") == 0)
			push_arg = strtok(NULL, " ");

		execute_function(opcode, &stack, line_number);
		line_number++;
	}
	free(line);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
