#include "monty.h"

/**
  * trim_spaces - function to clean spaces at the beginning
  * @str: The string to be cleaned
  * Delete spaces at the beginning of the command
  *
  * Return: the new command
  *
  */

char *trim_spaces(char *str)
{
	char *command;

	command = str;
	if (*(str + 0) == 32 || *(str + 0) == 9)
	{
		while (*command)
		{
			if (*command != 32 && *command != 9)
				return (command);
			command++;
		}
	}
	return (str);
}

/**
 * check_atoi - Function to analyze second argument
 * @str: The second argument of opcode
 * @n: The counter
 *
 * Analyze second argument of opcode
 *
 * Return: The number got by atoi, exit otherwise
 */

int check_atoi(char *str, unsigned int n)
{
	int i = 0, letter = 0, num = 0;

	if (str != NULL)
	{
		while (str[i] && !letter)
		{
			if ((str[i] > '9' || str[i] < '0') && str[i] != '-')
				letter = 1;
			i++;
		}

		num = atoi(str);
	}
	else
	{

		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	if (!num || letter)
	{
		if (((strcmp(str, "0") != 0)
					&& (strcmp(str, "-0") != 0))
					&& letter)
		{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
		}
	}
	return (num);
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
 * opcode_not_found - function that free malloc
 * @head: pointer to stack's head
 * @commands: The opcode in tokens
 * @buff: The line containing the opcode
 * @fd: The stream
 * @counter: The counter lines
 *
 * Free all malloc if opcode is not found
 *
 * Return: Always void
 **/

void opcode_not_found(stack_t *head, char **commands, char *buff, FILE *fd,
		int counter)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, commands[0]);
	free(commands);
	free(buff);
	_free_stack(head);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * check_ds - function that checks data structure
 * @opcode: The opcode command
 *
 * Checks if we are in a stack or a queue data structure
 *
 * Return: 1 if stack, 2 if queue
 **/

unsigned int check_ds(char *opcode)
{
	unsigned int ds = 0;

	if (strncmp(opcode, "queue", strlen(opcode)) == 0)
		ds = 2;
	else if (strncmp(opcode, "stack", strlen(opcode)) == 0)
		ds = 1;
	return (ds);
}
