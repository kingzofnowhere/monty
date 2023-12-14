#include "monty.h"


/**
 * push - The function that pushes a new node into the stack/Queue.
 * @stack: Doubly linked list.
 * @line_number: Position at which we are going to insert this new Node.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;

	/* Incase it is a fresh one*/
	if ((*stack) == NULL)
	{
		(*stack) = new;
	}
	else
	{
		new->next = (*stack);
		(*stack)->prev = new;
		(*stack) = new;
	}
}

/**
 * pall - function that prints all stack
 * @stack: Doubly Linked list.
 */
void pall(stack_t *stack)
{
	/* Print all stack elements */
	while (stack != NULL)
	{
		fprintf(stdout, "%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to a stack
 * @line_number: Line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->prev != NULL)
	{
		while (top->prev != NULL)
		{
			top = top->prev;
		}
	}
	fprintf(stdout, "%u\n", top->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: Pointer to a stack.
 * @line_number: Line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(top);
}
/**
 * free_stack - function that frees memory allocation of a stack.
 * @stack: doubly linked list to a stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
