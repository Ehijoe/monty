# Monty Interpreter

An interpreter for the monty language.

## monty.h

- Funtion prototypes
- Stack struct definition
- Instruction struct definition
- Command struct definition
    - opcode function
    - int arg
- Enum for type of stack

## main.c

### main

```
Check number of arguments
Open program file
line_no = 0
stack = NULL
stack_type = STACK

while (file_not_ended)
    line = getline()
    command = tokenize(line, line_no)
    run_command(command, &stack, &stack_type)
    line_no++

Close program file
Exit successfully
```

### run_command

```
command.func(stack, stack_type, argument)
```

### tokenize

## stack.c

### stack_push

### stack_pop

### stack_is_empty

## print_opcodes.c

### opcode_pall

### opcode_pint

### opcode_nop

## maths_opcodes.c

### opcode_add

### opcode_sub *Advanced*

### opcode_div *Advanced*

### opcode_mul *Advanced*

### opcode_mod *Advanced*

## stack_opcodes.c

### opcode_push

### opcode_pop

### opcode_swap

### opcode_rotl *Advanced*

### opcode_rotr *Advanced*

## mode_opcodes.c *Advanced*

### opcode_stack *Advanced*

### opcode_queue *Advanced*

## string_opcodes.c *Advanced*

### opcode_pchar *Advanced*

### opcode_pstr *Advanced*
