#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

/**
 * enum stack_type_e - The types of stacks available
 * @STACK: A regular stack (LIFO)
 * @QUEUE: A queue (FIFO)
 */
typedef enum stack_type_e
{
	STACK,
	QUEUE
} stack_type_e;

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

/**
 * opcode_func - Funtion that runs an opcode
 */
typedef void (*opcode_func)(stack_t **,
			    stack_type_e *,
			    unsigned long int,
			    int);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * @argc: number of arguments it takes
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	opcode_func f;
	int argc;
} instruction_t;

/**
 * struct command_s - opcode function and its argument
 * @f: The opcode function
 * @arg: The argument
 *
 * Description: Representation of a command line to be executed
 */
typedef struct command_s
{
	opcode_func f;
	int arg;
} command_t;


/* main.c */

void run_command(command_t command, stack_t **stack,
		 stack_type_e *stack_type, unsigned long int line_no);
command_t tokenize(char *line, unsigned int line_no);
int get_opcode_func(char *opcode, command_t *command);


/* stack.c */

void stack_push(stack_t **stack, int n);
void queue_push(stack_t **stack, int n);
int stack_pop(stack_t **stack);
void stack_free(stack_t *stack);
int stack_len(stack_t *stack);


/* error.c */

void error_exit(int set_vars, stack_t **stack, FILE *program, char **buffer);


/* stack_opcodes.c */

void opcode_push(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);
void opcode_pop(stack_t **stack, stack_type_e *stack_type,
		unsigned long int line_no, int arg);
void opcode_swap(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);
void opcode_rotl(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);
void opcode_rotr(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);


/* mode_opcodes.c */

void opcode_stack(stack_t **stack, stack_type_e *stack_type,
		  unsigned long int line_no, int arg);
void opcode_queue(stack_t **stack, stack_type_e *stack_type,
		  unsigned long int line_no, int arg);


/* print_opcodes.c */

void opcode_pall(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);
void opcode_pint(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);
void opcode_pchar(stack_t **stack, stack_type_e *stack_type,
		  unsigned long int line_no, int arg);
void opcode_pstr(stack_t **stack, stack_type_e *stack_type,
		 unsigned long int line_no, int arg);

#endif
