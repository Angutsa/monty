#include <ctype.h>
#include "monty.h"

/**
 * f_pint - print the value at the top of the stack
 * @head: stack head
 * @line_number: monty file line number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_fail(head);
	}

	printf("%d\n", (*head)->n);
}
