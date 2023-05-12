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
/**
 * _rotl - function
 * @head: Pointer to the stack
 * @n: The line nummber
 *
 * Return: Void
 **/
void _rotl(stack_t **head, __attribute__((unused))unsigned int n)
{
	stack_t *tmp_top = *head;
	stack_t *tmp_end = *head;
	int top;

	if ((*head) == NULL || (*head)->next == NULL)
		return;

	top = (*head)->n;
	tmp_top = (*head)->next;
	while (tmp_top)
	{
		tmp_end->n = tmp_top->n;
		if (tmp_top->next == NULL)
			tmp_top->n = top;
		tmp_top = tmp_top->next;
		tmp_end = tmp_end->next;
	}
}
/**
 * _rotr - function
 * @head: Pointer to the stack
 * @n: The line nummber
 *
 * Return: Void
 **/
void _rotr(stack_t **head, __attribute__((unused))unsigned int n)
{
	stack_t *tmp_top = NULL;
	stack_t *tmp_end = *head;
	int last;

	if ((*head) == NULL || (*head)->next == NULL)
		return;

	while (tmp_end->next != NULL)
		tmp_end = tmp_end->next;
	last = tmp_end->n;
	tmp_top = tmp_end->prev;
	while (tmp_top)
	{
		tmp_end->n = tmp_top->n;
		if (tmp_top->prev == NULL)
			tmp_top->n = last;
		tmp_top = tmp_top->prev;
		tmp_end = tmp_end->prev;
	}
}
