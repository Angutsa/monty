#include <ctype.h>
#include "monty.h"

/**
 * f_mul- multiplies the two top elements of the stack
 * @head: stack head
 * @line_number: monty file line number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int line_number)
{
	int prod;
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
				line_number);
		exit_fail(head);
	}

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
				line_number);
		exit_fail(head);
	}

	prod = (*head)->n - ((*head)->next)->n;
	*head = (*head)->next;
	(*head)->n = prod;
	free(tmp);
}
