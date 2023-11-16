#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the stack.
 * @value: Value to be pushed onto the stack.
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = (int)value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - Prints all elements in the stack.
 * @stack: Double pointer to the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * pchar - Prints the ASCII character of the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char ascichar;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	ascichar = (char)((*stack)->n);
	fprintf(stdout, "%c", ascichar);
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
