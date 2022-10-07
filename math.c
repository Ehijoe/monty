#include <stdlib.h>
#include <stdio.h>

#include "monty.h"

/**
 * opcode_add - Add the top two elements on the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_add(stack_t **stack,
		__attribute__ ((unused)) stack_type_e * stack_type,
		unsigned long int line_no,
		__attribute__ ((unused)) int arg)
{
	int a, b, c;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%ld: can't add, stack too short\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	a = stack_pop(stack);
	b = stack_pop(stack);
	c = b + a;
	stack_push(stack, c);
}

/**
 * opcode_add - computes the remainder of TOS1 / TOS
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_mod(stack_t **stack,
		__attribute__ ((unused)) stack_type_e * stack_type,
		unsigned long int line_no,
		__attribute__ ((unused)) int arg)
{
	int a, b, c;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%ld: can't mod, stack too short\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	a = stack_pop(stack);
	if (a == 0)
	{
		fprintf(stderr, "L%ld: division by zero\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	b = stack_pop(stack);
	c = b % a;
	stack_push(stack, c);
}

/**
 * opcode_sub - Subtract the top two elements on the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_sub(stack_t **stack,
		__attribute__ ((unused)) stack_type_e * stack_type,
		unsigned long int line_no,
		__attribute__ ((unused)) int arg)
{
	int a, b, c;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%ld: can't sub, stack too short\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	a = stack_pop(stack);
	b = stack_pop(stack);
	c = b - a;
	stack_push(stack, c);
}

/**
 * opcode_mul - Multiply the top two elements on the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_mul(stack_t **stack,
		__attribute__ ((unused)) stack_type_e * stack_type,
		unsigned long int line_no,
		__attribute__ ((unused)) int arg)
{
	int a, b, c;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%ld: can't mul, stack too short\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	a = stack_pop(stack);
	b = stack_pop(stack);
	c = a * b;
	stack_push(stack, c);
}

/**
 * opcode_div - Divide the top two elements on the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_div(stack_t **stack,
		__attribute__ ((unused)) stack_type_e * stack_type,
		unsigned long int line_no,
		__attribute__ ((unused)) int arg)
{
	int a, b, c;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%ld: can't div, stack too short\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	a = stack_pop(stack);
	if (a == 0)
	{
		fprintf(stderr, "L%ld: division by zero\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	b = stack_pop(stack);
	c = b / a;
	stack_push(stack, c);
}
