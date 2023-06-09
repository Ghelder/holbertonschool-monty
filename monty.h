#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>


extern char **commands;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* OPCODES */
void _push(stack_t **, unsigned int);
void _push_queue(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);
void _pchar(stack_t **, unsigned int);
/* 2 */
void _pstr(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);


/* SUPPORT */
void read_line(char *, stack_t **);
char **tokenize_opcode(char *);
int get_opcode(char **commands, unsigned int, stack_t **, unsigned int);
void _free_stack(stack_t *);
void check_getline(char *, stack_t *, FILE *);
int check_atoi(char *, unsigned int);
char *trim_spaces(char *str);
void opcode_not_found(stack_t *head, char **commands, char *buff, FILE *fd,
		int counter);
unsigned int check_ds(char *opcode);

#endif /* MONTY_H */
