#include <stdlib.h>
#include <stdio.h>

#include "monty.h"


/**
 * stack_push - Push an item onto a stack
 * @stack: Pointer to top of stack
 * @n: Value to push
 */
void stack_push(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error_exit(0, NULL, NULL, NULL);
	}

	new->n = n;
	new->next = NULL;
	new->prev = *stack;
	if (new->prev != NULL)
	{
		new->prev->next = new;
	}
	*stack = new;
}

/**
 * queue_push - Enqueue an item onto a queue
 * @stack: Pointer to top of stack
 * @n: Value to push
 */
void queue_push(stack_t **stack, int n)
{
	stack_t *new, *bottom;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error_exit(0, NULL, NULL, NULL);
	}

	new->n = n;
	new->prev = NULL;

	bottom = *stack;
	if (bottom == NULL)
	{
		*stack = new;
		new->next = NULL;
	}
	else
	{
		while (bottom->prev != NULL)
			bottom = bottom->prev;
		new->next = bottom;
		bottom->prev = new;
	}
}

/**
 * stack_pop - Pop an item off a stack
 * @stack: Pointer to top of stack
 *
 * Return: The popped value or 0 if stack is too small
 */
int stack_pop(stack_t **stack)
{
	int val;
	stack_t *to_del;

	if (stack == NULL || *stack == NULL)
		return (0);
	to_del = *stack;
	val = to_del->n;
	*stack = to_del->prev;
	if (to_del->prev != NULL)
		to_del->prev->next = NULL;
	free(to_del);
	return (val);
}

/**
 * stack_free - Free memory allocated for a stack
 * @stack: Pointer to the top of the stack
 */
void stack_free(stack_t *stack)
{
	stack_t *curr;

	while (stack != NULL)
	{
		curr = stack->prev;
		free(stack);
		stack = curr;
	}
}

/**
 * stack_len - Get the lenght of a stack
 * @stack: stack to measure
 *
 * Return: The number of nodes in the stack
 */
int stack_len(stack_t *stack)
{
	int i;

	for (i = 0; stack != NULL; i++)
		stack = stack->prev;
	return (i);
}
