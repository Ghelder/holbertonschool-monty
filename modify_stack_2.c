#include "monty.h"
/**
 * _pstr - Function to print elements
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Print the entire stack
 *
 * Return: Void
 */
void _pstr(stack_t **head, __attribute__((unused))unsigned int n)
{
	stack_t *temp = *head;

	while (temp && temp->n > 0 && temp->n < 127)
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
