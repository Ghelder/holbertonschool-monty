#include "monty.h"

/**
 * main - Entry point
 * @argc: The number of arguments passed
 * @argv: The array containing the arguments
 *
 * [[PENDING ...]]
 *
 * Return: 0 all success
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_line(argv[1], &stack);
	_free_stack(stack);
	return (0);
}
