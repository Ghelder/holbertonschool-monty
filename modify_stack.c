#include "monty.h"

/**
 * _push - function that adds a new node
 * @head: pointer to stack_t pointer
 * @n: line number
 *
 * Push a new element in the stack
 *
 * Return: Void
 **/
void _push(stack_t **head, unsigned int n)
{
	stack_t *new = NULL;
	int num = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = check_atoi(commands[1], n);
	new->n = num;
	new->prev = NULL;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
}
/**
 * _pop - function that deletes a node at the top
 * @head: Pointer to stack_t pointer
 * @n: The line in the file
 *
 * Return: Void
 **/
void _pop(stack_t **head, unsigned int n)
{
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	*head = tmp->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
}
