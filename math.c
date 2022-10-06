#include <stdlib.h>
#include <stdio.h>

#include "monty.h"

/*
 * add - add funtion for the TOS1 & TOS
 * @stack - input
 * Return - mofified list
 */
void add(stack_t *stack)
{
	if ((stack_len(stack)) < 2)
	{

		return();
	}
	stack_t *temp;
	temp = *stack;
	int a, b, c;
	a = stack_pop(&temp);
	b = stack_pop(&temp);
	c = a + b;
	stack_push(&temp, c);
}
