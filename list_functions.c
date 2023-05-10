#include "monty.h"

/**
 * _push - function that adds a new node
 * @head: pointer to stack_t pointer
 * @n: line number
 *
 * Return: Void
 **/
void _push(stack_t **head, unsigned int n)
{
	stack_t *new = NULL;
	int num;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(commands[1]);
	if (!num)
	{
		fprintf(stderr, "L%d: usage: push integer", n);
		exit(EXIT_FAILURE);
	}
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
 * _free_stack - function that frees a list
 * @head: pointer to stack's head
 *
 * Return: Always void
 **/
void _free_stack(stack_t *head)
{
	stack_t *ptr = head;
	stack_t *tmp;

	while (head != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		tmp = ptr->prev;
		if (tmp == NULL)
		{
			free(ptr);
			return;
		}
		free(tmp->next);
		tmp->next = NULL;
		ptr = head;
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
		fprintf(stderr, "L%d: can't pop an empty stack", n);
		exit(EXIT_FAILURE);
	}
	(*head) = tmp->next;
	(*head)->prev = NULL;
	free(tmp);
}

/**
 * _pall - Function to print elements
 * @head: Pointer to the stack
 * @n: The line number
 *
 * Prints all the elements of a stack
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
