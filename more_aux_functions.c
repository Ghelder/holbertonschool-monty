#include "monty.h"

/**
 * check_getline - function that checks getline
 * @buff: The line containing the opcode
 * @head: The head of the stack or queue
 * @fd: The FILE stream
 *
 * Checks if getline finds an EOF
 *
 * Return: Void
 **/

void check_getline(char *buff, stack_t *head, FILE *fd)
{
	free(buff);
	_free_stack(head);
	fclose(fd);
	exit(EXIT_SUCCESS);

}
