#include <stdio.h>

#include "monty.h"


void opcode_pall(stack_t **stack,
		 __attribute__ ((unused)) stack_type_e *stack_type,
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
