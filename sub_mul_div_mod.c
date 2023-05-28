#include "monty.h"

/**
 * sub - function subtracts the integer in the top stack from second top
 * @stack: stack
 * @line_number: line number where command is located
 */
void sub(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int total;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->next->n - (*stack)->n);
	(*stack)->next->n = total;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: stack
 * @line_number: line number where command is located
 */
void mul(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int total;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->n * (*stack)->next->n);
	(*stack)->next->n = total;
	pop(stack, line_number);
}

/**
 * division - function divides the second top element of the stack
 * by the top element of the stack.
 * @stack: stack
 * @line_number: line number where command is located
 */
void division(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int total;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->n + (*stack)->next->n);
	(*stack)->next->n = total;
	pop(stack, line_number);
}

/**
 * mod - function computes the rest of the division of the second top element of the stack
 * by the top element of the stack.
 * @stack: stack
 * @line_number: line number where command is located
 */
void mod(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int total;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->next->n % (*stack)->n);
	(*stack)->next->n = total;
	pop(stack, line_number);
}
