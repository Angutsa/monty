#include <stdio.h>
#include <string.h>
#include "monty.h"

void call_opcode(stack_t **head);

/**
  * execute_opcode - gets and executes the instruction
  * @line: entire line from monty file
  * @head: stack head
  */
void execute_opcode(stack_t **head, char *line)
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
		while (arg[0] == ' ' || arg[0] == 9)
		{
			arg = arg + 1;
		}
		arg[1] = '\0';

		tmp = strchr(instruction, ' ');
		*tmp = '\0';
	}

	/** Compare and execute instruction */
	bus.content = instruction;
	bus.arg = arg;
	call_opcode(head);
}

/**
  * call_opcode - executes the instruction
  * @head: stack head
  */
void call_opcode(stack_t **head)
{
	int i;
	instruction_t opcode_list[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap}, /*
		{"add", f_add},
		{"nop", f_nop},*/
		{NULL, NULL}
	};

	for (i = 0; opcode_list[i].opcode != NULL; i++)
	{
		if (strcmp(bus.content, opcode_list[i].opcode) == 0)
		{
			opcode_list[i].f(head, bus.line);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", bus.lifi,
			bus.content);
	exit(EXIT_FAILURE);
}
