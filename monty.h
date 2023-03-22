#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>

/* Data structure for the stack */
typedef struct stack_s {
    int n;
    struct stack_s *next;
} stack_t;

/* Global variable for the stack */
extern stack_t *stack;

/* Function prototypes */
void push(char *arg);
void pall(void);

#endif /* MONTY_H */

