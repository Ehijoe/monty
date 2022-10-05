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
