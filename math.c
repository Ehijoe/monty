#include <stdlib.h>
#include <stdio.h>

#include "monty.h"

/*
 * opcode_add - add funtion for the TOS1 & TOS
 * @stack - input
 * Return - mofified list
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
	c = a + b;
	stack_push(stack, c);
}
