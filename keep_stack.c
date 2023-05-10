#include "monty.h"
/**
 * _pall - Function to print elements
 * @head: Pointer to the stack
 * @n: The line number
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
	(void)head;
	(void)n;
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
	(void)head;
	(void)n;
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
}
