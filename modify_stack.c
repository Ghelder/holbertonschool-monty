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
 * _push_queue - function that adds a new node
 * @head: pointer to stack_t pointer
 * @n: line number
 *
 * Add a new node at the tail of the queue
 *
 * Return: Void
 **/
void _push_queue(stack_t **head, unsigned int n)
{
	stack_t *new = NULL, *temp;
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
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
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
