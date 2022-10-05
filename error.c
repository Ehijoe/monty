#include <stdio.h>
#include <stdlib.h>

#include "monty.h"

/**
 * error_exit - Free resources and exit with failure
 */
void error_exit(int set_vars, stack_t **stack, FILE *program, char **buffer)
{
	static stack_t **stack_store;
	static FILE *program_store;
	static char **buffer_store;

	if (!set_vars)
	{
		fclose(program_store);
		stack_free(*stack_store);
		free(*buffer_store);
		exit(EXIT_FAILURE);
	}
	stack_store = stack;
	program_store = program;
	buffer_store = buffer;
}
