#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Data Structures */
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * De
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * enum stack_mode_t - enumeration for mode types
 * @MODE_STACK: represents stack mode (value 0)
 * @MODE_QUEUE: represents queue mode (value 1)
 *
 * Description: enumeration for differentiating between stack and queue modes
 * in the Monty program.
 */
typedef enum
{
	MODE_STACK,
	MODE_QUEUE
} stack_mode_t;

/**
 * struct monty_program_s -structure for Monty program's information
 * @stack: pointer to the top of the stack
 * @line_num: current line number in the script
 * @script_file: file pointer to the Monty bytecode file
 * @current_line: current line from the file
 * @current_opcode: current opcode being executed
 * @current_arg: current argument for the opcode, if applicable
 * @mode: Mode of operation (MODE_STACK or MODE_QUEUE)
 *
 * Description: holds all the necessary information to manage a Monty
 * bytecode script, including the state of the stack, the current
 * line and opcode being processed, and the mode of operation.
 */
typedef struct monty_program_s
{
	stack_t *stack;
	unsigned int line_num;
	FILE *script_file;
	char *current_line;
	char *current_opcode;
	int current_arg;
	stack_mode_t mode;
} monty_program_t;

extern monty_program_t program;
extern monty_program_t *program_ptr;
extern char **environ;

/* core.c */
void parse_line(monty_program_t *program_ptr);
void execute_opcode(monty_program_t *program_ptr);
void free_stack(stack_t *stack);

/* 1-opcodes.c */
void push_opcode(monty_program_t *program_ptr);
void pall_opcode(monty_program_t *program_ptr);
void pint_opcode(monty_program_t *program_ptr);
void pop_opcode(monty_program_t *program_ptr);
void swap_opcode(monty_program_t *program_ptr);

/* 2-opcodes.c */
void add_opcode(monty_program_t *program_ptr);
void nop_opcode(monty_program_t *program_ptr);
void sub_opcode(monty_program_t *program_ptr);
void div_opcode(monty_program_t *program_ptr);
void mul_opcode(monty_program_t *program_ptr);

/* 3-opcodes.c */
void mod_opcode(monty_program_t *program_ptr);
void pchar_opcode(monty_program_t *program_ptr);
void pstr_opcode(monty_program_t *program_ptr);
void rotl_opcode(monty_program_t *program_ptr);
void rotr_opcode(monty_program_t *program_ptr);

/* 4-opcodes.c */
void stack_opcode(monty_program_t *program_ptr);
void queue_opcode(monty_program_t *program_ptr);

#endif /* MONTY_H */
