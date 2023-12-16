#include "monty.h"

/**
 * swap - This swaps the top two elements of the stack.
 * @stack: Points to a stack.
 * @line_number: Line number.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = (*stack)->next;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    first->next = second->next;
    if (second->next != NULL) {
        second->next->prev = first;
    }

    first->prev = second;
    second->prev = NULL;
    second->next = first;
    *stack = second;
}

/**
 * add -  This adds the top two elements of the stack.
 * @stack: Points to a stack.
 * @line_number: Line number.
 */

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}

/**
 * nop -  doesn’t do anything. 
 * @stack: Pointer to a stack
 * @line_number: line number.
 */

void nop(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element of the stack.
 * @stack: Point to a stack.
 * @line_number: line number.
 */

void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n -= (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}

/**
 * div_stack - divides the second top element of the stack by the top element of the stack.
 * @stack: Points to a stack.
 * @line_number: line number.
 */

void div_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}
