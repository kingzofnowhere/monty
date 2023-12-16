#include "monty.h"
#include <stdio.h>

#define BUFSIZE 256

/**
 * main - Entry point.
 * @argc: Number of arguments passed in the file.
 * @argv: Argument list.
 * Return: integer.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[BUFSIZE];
	stack_t *stack;
	unsigned int line_number = 0;

	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, BUFSIZE, file))
	{
		line_number++;
		buffer[strcspn(buffer, "\n")] = 0;
		command(buffer, &stack, line_number);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
