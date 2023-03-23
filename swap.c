#include <ctype.h>
#include "monty.h"

/**
 * f_swap - swaps the two top elements of the stack
 * @head: stack head
 * @line_number: monty file line number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit_fail(head);
	}

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit_fail(head);
	}

	tmp = *head;
	*head = tmp->next;
	(*head)->prev = tmp->prev;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = *head;
	(tmp->next)->prev = tmp;
}
