#include "monty.h"

/**
 * main - Entry point
 * @argc: The number of arguments passed
 * @argv: The array containing the arguments
 *
 * Read opcodes from a file
 *
 * Return: 0 all success
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_line(argv[1], &stack);
	_free_stack(stack);
	return (0);
}
