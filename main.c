#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments (Should be 2)
 * @argv: Argument list (Second element if program filename)
 *
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	stack_type_e stack_type = STACK;
	char *line = NULL;
	unsigned long int line_size = 0, line_no = 1;
	FILE *program;
	command_t command;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	program = fopen(argv[1], "r");
	if (program == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	error_exit(1, &stack, program, &line);

	while (getline(&line, &line_size, program) != -1)
	{
		command = tokenize(line, line_no);
		run_command(command, &stack, &stack_type, line_no);
		line_no++;
	}

	free(line);
	stack_free(stack);
	fclose(program);
	return (EXIT_SUCCESS);
}

/**
 * run_command - Run a command line
 * @command: Command to run
 * @stack: Stack to run the command on
 * @stack_type: Type of the stack (Stack or Queue)
 * @line_no: Line of the command in the program
 */
void run_command(command_t command, stack_t **stack,
		 stack_type_e *stack_type, unsigned long int line_no)
{
	if (command.f == NULL)
		return;
	command.f(stack, stack_type, line_no, command.arg);
}

/**
 * tokenize - Parse a command line
 * @line: command line to parse
 * @line_no: line number
 *
 * Return: The parsed command NULL if empty or comment
 */
command_t tokenize(char *line, unsigned int line_no)
{
	char *opcode;
	command_t command = {NULL, 0};
	int argc;

	opcode = strtok(line, " \t\n\v\f\r");
	if (opcode == NULL || opcode[0] == '#')
		return (command);

	argc = get_opcode_func(opcode, &command);
	if (argc == 1)
	{
		char *arg;
		char *endptr;

		arg = strtok(NULL, " \t\n\v\f\r");
		if (arg == NULL)
		{
			fprintf(stderr,
				"L%d: usage: %s integer\n",
				line_no, opcode);
			error_exit(0, NULL, NULL, NULL);
		}
		command.arg = (int) strtol(arg, &endptr, 10);
		if (errno != 0 || *endptr != '\0' || arg == endptr)
		{
			fprintf(stderr,
				"L%d: usage: %s integer\n",
				line_no, opcode);
			error_exit(0, NULL, NULL, NULL);
		}
	}
	else if (argc == -1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
		error_exit(0, NULL, NULL, NULL);
	}

	return (command);
}

/**
 * get_opcode_func - Fill the correct opcode function into a command
 * @opcode: The opcode to run
 * @command: Pointer to the command to change
 *
 * Return: The number of arguments required
 */
int get_opcode_func(char *opcode, command_t *command)
{
	int i;
	instruction_t opcodes[] = {
		{"push", opcode_push, 1},
		{"pall", opcode_pall, 0},
		{"nop", NULL, 0},
		{"pop", opcode_pop, 0},
		{"swap", opcode_swap, 0},
		{"rotl", opcode_rotl, 0},
		{"rotr", opcode_rotr, 0},
		{"pint", opcode_pint, 0},
		{"pchar", opcode_pchar, 0},
		{"pstr", opcode_pstr, 0},
		{NULL, NULL, 0}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			command->f = opcodes[i].f;
			return (opcodes[i].argc);
		}
	}
	return (-1);
}
