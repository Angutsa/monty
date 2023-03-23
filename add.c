#include <ctype.h>
#include "monty.h"

/**
 * f_add - adds the two top elements of the stack
 * @head: stack head
 * @line_number: monty file line number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int line_number)
{
	int sum;
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		exit_fail(head);
	}

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		exit_fail(head);
	}

	sum = atoi((*head)->n) + atoi(((*head)->next)->n);
	*head = (*head)->next;
	(*head)->n = sum;
	free(tmp);
}
