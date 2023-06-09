#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

FILE *open_file(char *filename);
void close_file(char *filename);

/**
  * main - monty bytecodes interpreter
  * @argc: number of arguments
  * @argv: array of arguments passed
  * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
  */
int main(int argc, char **argv)
{
	FILE *fp;
	int linenumber = 0, line_max = 1000;
	char *line = malloc(sizeof(char) * line_max), *tmp = "";
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = open_file(argv[1]);
	bus.file = fp;
	bus.lifi = 0; /* Edit once queue implementation is added */

	while (tmp)
	{
		tmp = fgets(line, line_max, fp);
		if (feof(fp))
		{
			break;
		}
		else if (tmp == NULL)
		{
			fprintf(stderr, "Can't read file %s\n", argv[1]);
			exit_fail(&head);
		}

		line[strlen(line) - 1] = '\0'; /* strip newline character */
		linenumber++;
		bus.line = linenumber;
		execute_opcode(&head, line);
	}

	close_file(argv[1]);
	free_stack(head);
	free(line);
	return (EXIT_SUCCESS);
}

/**
  * open_file - opens a file
  * @filename: name of the file to open
  * Return: returns the file pointer for the file
  */
FILE *open_file(char *filename)
{
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fp);
}

/**
  * close_file - closes the file
  * @filename: name of the file
  */
void close_file(char *filename)
{
	if (fclose(bus.file) != 0)
	{
		fprintf(stderr, "Error: Can't close file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
