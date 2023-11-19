#include "monty.h"
/**
 * pop - remove the top
 * @head: stack head
 * @line_number: line_number
*/
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * pint - prints the top
 * @head: stack head
 * @line_number: line_number
*/
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;

		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
/**
  *rotl- rotates the stack to the top
  *@head: stack head
  *@line_number: line_number
 */
void rotl(stack_t **head,  unsigned int line_number)
{
	stack_t *tmp = *head, *aux;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
/**
  *rotr- rotates the stack to the bottom
  *@head: stack head
  *@line_number: line_number
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *copy;
	(void)line_number;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
