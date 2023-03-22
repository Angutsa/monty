#include "monty.h"

/* Global variable for the stack */
stack_t *stack = NULL;

/* Function to push an element to the stack */
void push(char *arg)
{
    int n;

    if (!arg || !*arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);

    if (n == 0 && *arg != '0')
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = stack;
    stack = new_node;
}

/* Function to print all the elements on the stack */
void pall(void)
{
    stack_t *current_node = stack;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}
