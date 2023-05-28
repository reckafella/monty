#include "monty.h"
/**
 * push - push an integer into the stack
 * @stack: stack
 * @line_number: line number where command is located
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n = push_arg;

	if (is_numeric(n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!add_node_end(stack, atoi(push_arg)))
		exit(EXIT_FAILURE);
}
/**
 * pall - print all elements starting with the top most
 * @stack: stack
 * @line_number: line number where command is located
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 * pint - print top most element in a stack
 * @stack: stack
 * @line_number: line number where command is located
 */
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * pop - remove the top most element from stack
 * @stack: stack
 * @line_number: line number where command is located
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;

	/* prevents errors cause next line might assign a NULL */
	if (!*stack)
		return;

	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number where command is located
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	__asm__ volatile("nop");
}
