#include "monty.h"

/**
  * free_stack - frees the stack linked list
  * @head: head node
  */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	free_stack(head->next);
	free(head);
}


/**
  * addnode - adds nodes to the stack
  * @head: head node
  * @n: integer value for node
  */
void addnode(stack_t **head, int n)
{
	stack_t *node;
	stack_t *h = *head;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_fail(head);
	}

	if (h == NULL)
	{
		node->n = n;
		node->prev = NULL;
		node->next = NULL;
		*head = node;
		return;
	}

	while (h->prev != NULL)
	{
		h = h->prev;
	}

	node->n = n;
	node->prev = h->prev;
	node->next = h;
	h->prev = node;
	*head = node;
}

/**
  * addqueue - adds nodes to the stack
  * @head: head node
  * @n: integer value for node
  */
void addqueue(stack_t **head, int n)
{
	/** TODO: implement **/
	printf("TODO: Implement addqueue\n");
	head = head + 1;
	n++;
}
