/**
 * add_dnodeint - function that adds a new node at the
 * beginning of a list
 * @head: pointer to stack_t pointer
 * @n: number
 *
 * Return: the new node
 **/
dlistint_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	} else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	return (*head);
}
/**
 * free_dlistint - function that frees a list
 * @head: pointer to stack_t struct
 *
 * Return: Always void
 **/
void free_dlistint(stack_t *head)
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
 * delete_dnodeint_at_index - function that deletes a node at index of a list
 * @head: Pointer to stack_t pointer
 * @index: Index
 *
 * Return: 1 if it succeeded, -1 if it failed
 **/
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp = *head;
	unsigned int cnt = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	while (cnt < index)
	{
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
		cnt++;
	}
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp->next == NULL)
	{
		tmp->prev->next = NULL;
		free(tmp);
		return (1);
	}
	free(tmp);
	return (1);
}
