#include "monty.h"

/**
 * push_opcode - adds a new node to the stack or queue
 * @program_ptr: pointer to the monty_program_t struct
 *
 * Description: this function creates a new stack node and adds it to the
 * top of the stack in stack mode (LIFO) or to the end of the queue in queue
 * mode (FIFO). It allocates memory for the new node and handles memory
 * allocation errors. It also updates the links between nodes accordingly.
 */
void push_opcode(monty_program_t *program_ptr)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = program_ptr->current_arg;
	new_node->next = NULL;
	if (program_ptr->mode == MODE_STACK)
	{
		new_node->prev = NULL;
		if (program_ptr->stack != NULL)
		{
			program_ptr->stack->prev = new_node;
		}
		new_node->next = program_ptr->stack;
		program_ptr->stack = new_node;
	}
	else
	{
		new_node->prev = NULL;
		if (program_ptr->stack == NULL)
			program_ptr->stack = new_node;
		else
		{
			temp = program_ptr->stack;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}
	}
}


/**
 * pall_opcode - Prints all the values on the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function traverses through the stack starting
 * from the top and prints each element's value. It continues until
 * it has traversed the entire stack.
 */
void pall_opcode(monty_program_t *program_ptr)
{
	stack_t *current_node = program_ptr->stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pint_opcode - prints  value at the top of the stack
 * @program_ptr: pointer to  monty_program_t struct
 *
 * Description: this function prints the value at the top of the stack.
 * If the stack is empty, it prints an error message and exits the program.
 */
void pint_opcode(monty_program_t *program_ptr)
{
	if (program_ptr->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", program_ptr->stack->n);
}

/**
 * pop_opcode - pops  top element off the stack
 * @program_ptr: pointer to  monty_program_t struct
 *
 * Description: this function removes  top element from the stack.
 * If the stack is empty, it prints an error message and exits the program.
 * It handles the removal and proper memory deallocation of the top element.
 */
void pop_opcode(monty_program_t *program_ptr)
{
	stack_t *temp;

	if (program_ptr->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	temp = program_ptr->stack;
	program_ptr->stack = program_ptr->stack->next;
	if (program_ptr->stack != NULL)
	{
		program_ptr->stack->prev = NULL;
	}
	free(temp);
}

/**
 * swap_opcode - Swaps  top two elements of the stack
 * @program_ptr: Pointer to  monty_program_t struct
 *
 * Description: this function swaps  top two elements on the stack.
 * If the stack does not have at least two elements, it prints an error
 * message and exits the program. It handles the re-linking of the stack
 * nodes to achieve the swap.
 */
void swap_opcode(monty_program_t *program_ptr)
{
	stack_t *first, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	first = program_ptr->stack;
	second = program_ptr->stack->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	program_ptr->stack = second;
}
