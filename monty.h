#ifndef MONTY_H
#define MONTY_H

/* header files */
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <bits/stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

#ifndef OPCODE_MAP
#define OPCODE_MAP    \
{    \
        {"push", push},    \
        {"pall", pall},    \
        {"pint", pint},    \
        {"pop", pop},    \
        {"nop", nop},    \
        {"add", add},    \
        {"swap", swap},    \
        {"sub", sub},    \
        {"div", division},    \
        {"mod", mod},    \
        {"mul", mul},    \
        {NULL, NULL}    \
};
#endif

/* DATA STRUCTURES */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

extern stack_t *stack;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* function prototypes */

/* nodes.c */
stack_t *add_node_end(stack_t **stack, const int n);
size_t print_stack(stack_t *stack);
void free_stack(stack_t *stack);
size_t stack_length(stack_t *stack);

/* basic_list_operations.c */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number); 
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* execution.c */
void execute_function(char *opcode, stack_t **stack, unsigned int line_number);

char *allocate_memory(char *filename);
void usage_error(void);
void file_io_error(char *filename);
int is_numeric(const char *str);

/* add_swap.c */
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* sub_mul_div_mod.c */
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* Obtain user input */
/* extern ssize_t get_delim(char **lineptr, size_t *n, int delim, FILE *stream);
extern ssize_t get_line(char **lineptr, size_t *n, FILE *stream); */

extern char *push_arg;

#ifndef MAX_LINE_LEN
#define MAX_LINE_LEN 1024
#endif /* MAX_LINE_LEN */

#endif /* MONTY_H */
