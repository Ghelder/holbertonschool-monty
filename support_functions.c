#include "monty.h"

char **commands = NULL;

/**
 * read_line - Function to read file
 * @head: Pointer to the stack
 * @filename: The path to the file
 *
 * Read the content of a file
 *
 * Return: Void
 */
void read_line(char *filename, stack_t **head)
{
	char *buff = NULL, *opcode;
	ssize_t chars;
	size_t size = 0;
	unsigned int counter = 0, run = 1, flag = 1, ds;
	FILE *fd;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (run)
	{
		chars = getline(&buff, &size, fd);
		counter++;
		if (chars == -1)
			check_getline(buff, *head, fd);
		opcode = trim_spaces(buff);
		if (opcode[0] == 35)
			continue;
		commands = tokenize_opcode(opcode);
		if (!commands)
			continue;
		ds = check_ds(commands[0]);
		if (ds)
		{
			flag = ds;
			free(commands);
			continue;
		}
		run = get_opcode(commands, counter, head, flag);
		if (run == 0)
			opcode_not_found(*head, commands, buff, fd, counter);
		free(commands);
	}
}


/**
 * get_opcode - Function to search an opcode
 * @head: Pointer to the stack
 * @commands: The opcodes tokenized
 * @counter: The counter
 * @ds: The data structure, 1 if stack, 2 if queue
 *
 * Search a opcode and execute its function
 *
 * Return: 1 on success, 0 otherwise
 */
int get_opcode(char **commands, unsigned int counter, stack_t **head,
		unsigned int ds)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", (ds == 1) ? _push : _push_queue}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, commands[0]) == 0)
		{
			opcodes[i].f(head, counter);
			return (1);
		}
		i++;
	}
	return (0);
}


/**
 * tokenize_opcode - Function to tokenize
 * @buff: The string containing the opcode
 *
 * Tokenize what's inside @buff
 *
 * Return: An array of tokens, NULL otherwise
 */
char **tokenize_opcode(char *buff)
{
	char **tokens = NULL, *token, *delim = " \n";
	int i = 0;

	token = strtok(buff, delim);
	if (token)
	{
		tokens = malloc(sizeof(char *) * 3);
		if (!tokens)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		while (token && i < 2)
		{
			tokens[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		tokens[i] = NULL;
		return (tokens);
	}
	return (tokens);
}

