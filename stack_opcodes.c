#include <stdio.h>

#include "monty.h"

/**
 * opcode_push - Opcode to push an int onto the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_push(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e *stack_type,
		 __attribute__ ((unused)) unsigned long int line_no,
		 int arg)
{
	stack_push(stack, arg);
}

/**
 * opcode_pop - Opcode to pop an int from the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_pop(stack_t **stack,
		__attribute__ ((unused)) stack_type_e *stack_type,
		unsigned long int line_no,
		__attribute__ ((unused)) int arg)
{
	if (stack_len(*stack) < 1)
	{
		fprintf(stderr, "L%ld: can't pop an empty stack", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	stack_pop(stack);
}

/**
 * opcode_swap - Opcode to swap the top two items on the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_swap(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e *stack_type,
		 unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	int len, first, second;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%ld: can't swap, stack too short", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	first = stack_pop(stack);
	second = stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

/**
 * opcode_rotl - Rotatate the stack so the top becomes the bottom
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_rotl(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e *stack_type,
		 __attribute__ ((unused)) unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	stack_t *top, *bottom;

	top = *stack;
	if (top == NULL || top->prev == NULL)
		return;
	bottom = *stack;
	while (bottom->prev != NULL)
		bottom = bottom->prev;
	*stack = top->prev;
	top->prev->next = NULL;
	top->prev = NULL;
	top->next = bottom;
	bottom->prev = top;
}

/**
 * opcode_rotr - Rotate the stack so the bottom becomes the top
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_rotr(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e *stack_type,
		 __attribute__ ((unused)) unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	stack_t *top, *bottom;

	top = *stack;
	if (top == NULL || top->prev == NULL)
		return;
	bottom = *stack;
	while (bottom->prev != NULL)
		bottom = bottom->prev;
	bottom->next->prev = NULL;
	bottom->next = NULL;
	bottom->prev = top;
	top->next = bottom;
	*stack = bottom;
}
