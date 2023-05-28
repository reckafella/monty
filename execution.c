#include "monty.h"

/**
 * execute_function - execute each instruction opcode
 * @opcode: first argument of each line read from file
 * @stack: doubly linked stack
 * @line_number: line number
 */

void execute_function(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = OPCODE_MAP;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}	
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
