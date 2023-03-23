#include "monty.h"
/**
 * f_pop - removes the top element
 * @head: stack head
 * @line_number: line number on opcode monty file
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				line_number);
		exit_fail(head);
	}

	h = *head;
	*head = h->next;
	free(h);
}
