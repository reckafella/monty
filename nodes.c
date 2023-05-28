#include "monty.h"

/**
 * add_node_end - add node at the end
 * @stack: pointer to first node
 * @n: integer data to add to the new node
 *
 * Return: address of the new element or NULL on failure
*/
stack_t *add_node_end(stack_t **stack, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 * print_stack - print all elements of a stack
 * @stack: pointer to first node
 *
 * Return: number of nodes
*/
/* size_t print_stack(stack_t *stack)
{
	size_t count = 0;
	stack_t *ptr = stack;

	if (ptr == NULL)
		return;

	while (ptr != NULL)
	{
		printf( "%d\n", ptr->n);
		ptr = ptr->next;
		count++;
	}

	return (count);
} */

/**
 * free_stack - free stack
 * @stack: first node
*/
void free_stack(stack_t *stack)
{
	stack_t *ptr;

	while (stack)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
	stack = NULL;
}
