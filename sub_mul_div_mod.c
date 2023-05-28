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
	int result;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->n * (*stack)->next->n);
	(*stack)->next->n = result;
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
	int result, first, second;

	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Deal with negative values in the stack */
	first = (*stack)->n, second = (*stack)->next->n;

	if (first < 0 || second < 0)
		result = (-1) * (abs(second) / abs(first));
	else
		result = (second / first);

	(*stack)->next->n = result;

	pop(stack, line_number);
}

/**
 * mod - function computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: stack
 * @line_number: line number where command is located
 */
void mod(stack_t **stack, unsigned int line_number)
{
	size_t stack_len = stack_length(*stack);
	int rem, first, second;

	/* If number of stacks is less than 2, print error to stderr */
	if (stack_len < 2 || !stack || !*stack)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* If top stack has n = 0, print error to stderr */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n, second = (*stack)->next->n;

	/* Deal with cases where n in one or both stacks is negative */
	if (first < 0 || second < 0)
		rem = (-1) * (abs(second) % abs(first));
	else
		rem = (second % first);

	(*stack)->next->n = rem;
	pop(stack, line_number);
}

/**
 * pchar - print top most element in a stack as a character
 * @stack: stack
 * @line_number: line number where command is located
 */
void pchar(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if ((*stack)->n < 1 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}
