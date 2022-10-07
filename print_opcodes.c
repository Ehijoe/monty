#include <stdio.h>

#include "monty.h"


/**
 * opcode_pall - Print all the numbers on the stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_pall(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e * stack_type,
		 __attribute__ ((unused)) unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	stack_t *curr;

	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}

/**
 * opcode_pint - Print the top number on a stack
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_pint(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e * stack_type,
		 unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	if (stack_len(*stack) < 1)
	{
		fprintf(stderr, "L%ld: can't pint, stack empty\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * opcode_pchar - Print the top of the stack as an ascii character
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_pchar(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e * stack_type,
		 unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	int val;

	if (stack_len(*stack) < 1)
	{
		fprintf(stderr, "L%ld: can't pchar, stack empty\n", line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	val = (*stack)->n;
	if (val < 0 || val > 127)
	{
		fprintf(stderr,
			"L%ld: can't pchar, value out of range\n",
			line_no);
		error_exit(0, NULL, NULL, NULL);
	}
	printf("%c\n", val);
}

/**
 * opcode_pstr - Print the stack as a string starting from the top
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_pstr(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e * stack_type,
		 __attribute__ ((unused)) unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	stack_t *curr;

	curr = *stack;
	while (curr != NULL && curr->n > 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->prev;
	}
	printf("\n");
}
