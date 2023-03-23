#include "monty.h"
/**
 * f_pop - prints the top
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
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
