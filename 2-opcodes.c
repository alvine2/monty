#include "monty.h"

/**
 * add_opcode - adds  top two elements of the stack
 * @program_ptr: pointer to monty_program_t struct
 *
 * Description: this function adds the top two elements of the stack.
 * If the stack does not have at least two elements, it prints an error
 * message and exits the program. It performs the addition and then removes
 * the top element from the stack.
 */
void add_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	top = program_ptr->stack;
	second = top->next;
	second->n += top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}

/**
 * nop_opcode - Does nothing
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function is a no-operation function. It is designed
 * to do nothing and is typically used as a placeholder or to avoid an
 * unused parameter warning.
 */
void nop_opcode(monty_program_t *program_ptr)
{
	(void)program_ptr;
}

/**
 * sub_opcode - Subtracts  top element from the
 * second top element of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: this function performs a subtraction between the top two
 * elements of the stack. If the stack does not have at least two elements,
 * it prints an error message and exits the program. After the subtraction,
 * the top element is removed from the stack.
 */
void sub_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	top = program_ptr->stack;
	second = top->next;
	second->n -= top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}

/**
 * div_opcode - Divides  second top element by the top element of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function performs a division of the second top element by
 * the top element of the stack. It checks if the stack has at least two
 * elements and if the top element (the divisor) is not zero. If any of these
 * conditions are not met, it prints an error message and exits the program.
 * After the division, the top element is removed from the stack.
 */
void div_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
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
	second->n /= top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}

/**
 * mul_opcode - Multiplies  second top element with
 * the top element of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: this function multiplies the second top element of the stack
 * with the top element. If the stack does not have at least two elements, it
 * prints an error message and exits the program. After performing the
 * multiplication, the top element is removed from the stack.
 */
void mul_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	top = program_ptr->stack;
	second = top->next;
	second->n *= top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}
