#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: Points to a stack
 * @line_number: Line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last = *stack;

    (void) line_number;

    while (last->next != NULL) {
        last = last->next;
    }

    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

/**
 * queue_custom - sets the format of the data to a stack (LIFO). This is the default behavior of the program.
 * @stack: Points to a stack.
 * @line_number: Line number
 */

void stack_custom(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
}


/**
 * queue_custom - sets the format of the data to a queue (FIFO).
 * @stack: points to a stack.
 * @line_number: Line number.
 */

void queue_custom(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
}
