#include "monty.h"

/**
 * _add - function that adds the top two elements of the stack
 * @head: Pointer to stack_t pointer
 * @n: The line in the file
 *
 * Return: Void
 **/
void _add(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int len = 0, num;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	num = temp->n;
	(*head)->n = (*head)->n + num;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _sub - function that subtracts the top two elements of the stack
 * @head: Pointer to stack_t pointer
 * @n: The line in the file
 *
 * Return: Void
 **/
void _sub(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int len = 0, num;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	num = temp->n;
	(*head)->n = (num > (*head)->n) ? num - (*head)->n : (*head)->n - num;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _div - function that divides the second top by the top element
 * @head: Pointer to stack_t pointer
 * @n: The line in the file
 *
 * Return: Void
 **/
void _div(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int len = 0, num;

	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = temp->n;
	(*head) = temp->next;
	(*head)->n = (*head)->n / num;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _mul - function that multiply the top two elements of the stack
 * @head: Pointer to stack_t pointer
 * @n: The line in the file
 *
 * Return: Void
 **/
void _mul(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int len = 0, num;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	num = temp->n;
	(*head)->n = (*head)->n * num;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _mod - function that module the second top by the top element
 * @head: Pointer to stack_t pointer
 * @n: The line in the file
 *
 * Return: Void
 **/
void _mod(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;
	int len = 0, num;

	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = temp->n;
	(*head) = temp->next;
	(*head)->n = (*head)->n % num;
	(*head)->prev = NULL;
	free(temp);
}

