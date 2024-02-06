#include "monty.h"

/**
 * mod_opcode - Performs a modulo operation on the second top and
 * top elements of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function performs a modulo operation on the second top
 * and top elements of the stack. It checks if the stack has at least two
 * elements and if the top element (the divisor) is not zero.
 * If any of these conditions are not met, it prints an error
 * message and exits the program. After the modulo operation, the top element
 * is removed from the stack.
 */
void mod_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	top = program_ptr->stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	second->n %= top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}

/**
 * pchar_opcode - Prints the char at the top of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function checks if the stack is not empty and if the value
 * at the top of the stack is within the ASCII character range. If so, it
 * prints the corresponding character. Otherwise, it prints an error message
 * and exits the program.
 */
void pchar_opcode(monty_program_t *program_ptr)
{
	int value;

	if (program_ptr->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	value = program_ptr->stack->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)value);
}

/**
 * pstr_opcode - Prints the string starting from the top of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: this function iterates through the stack and prints each value
 * as a character. It stops when the end of the stack is reached, the value is
 * 0, or the value is outside the ASCII range. After printing the characters,
 * it outputs a newline.
 */
void pstr_opcode(monty_program_t *program_ptr)
{
	stack_t *current = program_ptr->stack;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", (char)current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl_opcode - rotates the stack to the top
 * @program_ptr: pointer to the monty_program_t struct
 *
 * Description: this function rotates the stack to the top. The top element of
 * the stack becomes the last one, and the second top element becomes the new
 * top. If the stack is empty or has only one element, it does nothing.
 */
void rotl_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *bottom;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		return;
	}
	top = program_ptr->stack;
	bottom = top;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	program_ptr->stack = top->next;
	program_ptr->stack->prev = NULL;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}

/**
 * rotr_opcode - rotates the stack to the bottom
 * @program_ptr: pointer to the monty_program_t struct
 *
 * Description: this function rotates stack to bottom. The bottom
 * element of the stack becomes the new top, and the original top element
 * follows the new top.
 * If the stack is empty or has only one element, it does nothing.
 */
void rotr_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *bottom;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		return;
	}
	top = program_ptr->stack;
	bottom = top;
	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	if (bottom->prev)
	{
		bottom->prev->next = NULL;
	}
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	program_ptr->stack = bottom;
}
