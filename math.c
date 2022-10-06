#include <stdlib.h>
#include <stdio.h>

#include "monty.h"
/*
 * add - add funtion for the TOS1 & TOS
 * @stack - input
 * Return - mofified list
 */
stack_t add(stack_t **stack)
{
	stack_t *temp;
	int add = 0;
	int i = 0;
	temp = *stack;
	while(temp =! NULL || i > 2)
	{
		add += temp->n;
		stack_pop(temp)
		temp = temp->prev;
		i++;
	}
	return(temp);
}

