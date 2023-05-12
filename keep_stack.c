#include "monty.h"

/**
 * _pall - Function to print elements
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Print the entire stack
 *
 * Return: Void
 */
void _pall(stack_t **head, __attribute__((unused))unsigned int n)
{
	stack_t *temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - Function that prints the value at the top of the stack
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Return: Void
 */
void _pint(stack_t **head, unsigned int n)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _swap - Function that swaps the top two elements of the stack
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Prints all the elements of a stack
 *
 * Return: Void
 */
void _swap(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int len = 0, swap;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	swap = temp->n;
	temp->n = (*head)->n;
	(*head)->n = swap;
}

/**
 * _nop - Function that doesn’t do anything.
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Prints all the elements of a stack
 *
 * Return: Void
 */
void _nop(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
	;
}


/**
 * _pchar - Function to print character
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Print the number in character
 *
 * Return: Void
 */
void _pchar(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int num;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	num = temp->n;
	if (num < 33 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", num);
}

