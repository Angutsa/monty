#include <stdio.h>
#include <string.h>
#include "monty.h"

void call_opcode(char *instruction, char *arg, int linenumber);

/** TODO: Delete these temps **/
void f_push(stack_t **stack, unsigned int line_number)
{
	printf("push function called\n");
}

void f_pall(stack_t **stack, unsigned int line_number)
{
	printf("pall function called\n");
}

/**
  * execute_opcode - gets and executes the instruction
  * @line: entire line from monty file
  * @linenumber: line number of the opcode to execute
  */
void execute_opcode(char *line, int linenumber)
{
	char *instruction, *arg, *tmp;
	int i;

	/** Separate instruction and argument */
	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ' || line[i] == 9)
		{
			continue;
		}
		else
		{
			instruction = &(line[i]);
			break;
		}
	}

	arg = strchr(instruction, ' ');
	if (arg != NULL)
	{
		while(arg[0] == ' ' || arg[0] == 9)
		{
			arg = arg + 1;
		}
		arg[1] = '\0';
	
		tmp = strchr(instruction, ' ');
		*tmp = '\0';
	}

	/** Compare and execute instruction */
	call_opcode(instruction, arg, linenumber);
	
	/** TODO: Add implementation for bus struct */
}

/**
  * call_opcode - executes the instruction in the line
  * @instruction: monty instruction
  * @arg: argument to monty instruction
  * @arg: linenumber of argument
  */
void call_opcode(char *instruction, char *arg, int linenumber)
{
	int i;
	instruction_t opcode_list[] = {
		{"push", f_push},
		{"pall", f_pall}/*,
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop}*/,
		{NULL, NULL}
	};

	for (i = 0; opcode_list[i].opcode != NULL; i++)
	{
		if (strcmp(instruction, opcode_list[i].opcode) == 0)
		{
			opcode_list[i].f(NULL, linenumber);
			return;
		}
	}
	
	fprintf(stderr, "L%d: unknown instruction %s\n", linenumber,
			instruction);
	exit (EXIT_FAILURE);
}
