#include "monty.h"
/**
 * free_stack - Frees the entire stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
