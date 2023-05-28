#include "monty.h"

/**
 * add - function add the last two integer elements in the stack
 * @stack: stack
 * @line_number: line number where command is located
 */
void add(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int total;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->n + (*stack)->next->n);
	(*stack)->next->n = total;
	pop(stack, line_number);
	/* (*stack)->n = total; */
}
/**
 * swap - function add the last two integer elements in the stack
 * @stack: stack
 * @line_number: line number where command is located
 */
void swap(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int temp;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
