#include "monty.h"

/**
  * exit_fail - cleanly exits the program
  * @head: stack head
  */
void exit_fail(stack_t **head)
{
	fclose(bus.file);
	if (bus.content != NULL)
		free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
