#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @line_number: opcode line number on monty file (NOT USED)
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	(void)line_number;

	if (head == NULL || *head == NULL)
	{
		return;
	}

	h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
