#include "monty.h"

/**
 * mul_stack - multiplies the second top element of the stack with the top element of the stack.
 * @stack: Points to a stack
 * @line_number: line number.
 */

void mul_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n *= (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}

/**
 * mod_stack - computes the rest of the division of the second top element of the stack
 *              by the top element of the stack.
 * @stack: Points to a stack.
 * @line_number: line number.
 */

void mod_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: Points to a stack.
 * @line_number: line number.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
    int value;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = (*stack)->n;

    if (value < 0 || value > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%c\n", (char) value);
}

/**
 * pstr - prints the string starting at the top of the stack, followed by a new line.
 * @stack: Points to a stack.
 * @line_number: line number.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *printer = *stack;
    int value;

    if (*stack != NULL)
    {
        while (printer != NULL)
        {
            value = printer->n;
            if (value < 1 || value > 127)
            {
                break;
            }
            fprintf(stdout, "%c", (char) value);
            printer = printer->next;
            line_number++;
        }
    }
    fprintf(stdout, "\n");
}

/**
 * rotl - rotates the stack to the top.
 * @stack: Points to a stack.
 * @line_number: line number.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    stack_t *second = (*stack)->next;
    stack_t *current = second;

    (void) line_number;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = top;
    top->prev = current;
    top->next = NULL;
    (*stack) = second;
    second->prev = NULL;
}
