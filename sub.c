#include <ctype.h>
#include "monty.h"

/**
 * f_sub- subtracts the two top elements of the stack
 * @head: stack head
 * @line_number: monty file line number
 * Return: no return
*/
void f_sub(stack_t **head, unsigned int line_number)
{
	int dif;
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		exit_fail(head);
	}

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		exit_fail(head);
	}

	dif = (*head)->n - ((*head)->next)->n;
	*head = (*head)->next;
	(*head)->n = dif;
	free(tmp);
}
