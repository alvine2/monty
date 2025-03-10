#include "monty.h"

/**
 * stack_opcode - sets mode of the program to stack (LIFO)
 * @program_ptr: pointer to the monty_program_t struct
 *
 * Description: this function sets mode of the program to stack, which
 * means the program will operate in Last In First Out (LIFO) mode.
 */
void stack_opcode(monty_program_t *program_ptr)
{
	program_ptr->mode = 0;
}

/**
 * queue_opcode - sets the mode of the program to queue (FIFO)
 * @program_ptr: pointer to the monty_program_t struct
 *
 
void queue_opcode(monty_program_t *program_ptr)
{
	program_ptr->mode = 1;
}
