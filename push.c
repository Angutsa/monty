#include <ctype.h>
#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @line_number: monty file line number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0;

	if (bus.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (bus.arg[0] == '-')
		j++;

	for (; bus.arg[j] != '\0'; j++)
	{
		if (isdigit(bus.arg[j]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
