#include "monty.h"
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
