#include "monty.h"

/**
 * opcode_stack - Opcode to enter stack mode
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_stack(__attribute__ ((unused)) stack_t **stack,
		 stack_type_e *stack_type,
		 __attribute__ ((unused)) unsigned long int line_no,
		 __attribute__ ((unused)) int arg)
{
	*stack_type = STACK;
}

/**
 * opcode_queue - Opcode to enter queue mode
 * @stack: the stack
 * @stack_type: the type of stack
 * @line_no: The line number
 * @arg: The argument to the opcode
 */
void opcode_queue(__attribute__ ((unused)) stack_t **stack,
		  stack_type_e *stack_type,
		  __attribute__ ((unused)) unsigned long int line_no,
		  __attribute__ ((unused)) int arg)
{
	*stack_type = QUEUE;
}
