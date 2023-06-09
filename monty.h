#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>

/************************ STRUCTURES *********************************/

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack (or queue)
  * @next: points to the next element of the stack (or queue)
  *
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO
  */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
  * struct instruction_s - opcode and its function
  * @opcode: the opcode
  * @f: function to handle the opcode
  *
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * bus_s - struct to store opcode details
  * @arg: opcode argument
  * @file: monty file pointer
  * @content: opcode instruction
  * @line: line number of opcode in monty file
  * @lifi: 0 if structure is a stack and 1 if structure is a queue
  */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int line;
	int lifi;
}  bus_t;

extern bus_t bus;
bus_t bus;

/************************* PROTOTYPES ***********************************/

void execute_opcode(stack_t **head, char *line);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void exit_fail(stack_t **head);

void f_push(stack_t **head, unsigned int line_number);
void f_pall(stack_t **head, unsigned int line_number);
void f_pop(stack_t **head, unsigned int line_number);
void f_pint(stack_t **head, unsigned int line_number);
void f_swap(stack_t **head, unsigned int line_number);
void f_add(stack_t **head, unsigned int line_number);
void f_nop(stack_t **head, unsigned int line_number);
void f_sub(stack_t **head, unsigned int line_number);
void f_mul(stack_t **head, unsigned int line_number);

#endif /* MONTY_H */
