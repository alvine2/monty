#include "monty.h"

/**
 * parse_line - parses a line of Monty bytecode and updates program state
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: this function takes a line from the Monty bytecode file,
 * extracts the opcode and its argument (if present), and updates the
 * program's state accordingly. If an error is found (e.g., invalid integer),
 * the function will print an error message and exit the program.
 */
void parse_line(monty_program_t *program_ptr)
{
	char *token;
	char *endptr;
	long arg;
	char *line;

	line = program_ptr->current_line;
	while (*line == ' ')
	{
		line++;
	}
	if (*line == '#' || *line == '\0')
	{
		program_ptr->current_opcode = NULL;
		return;
	}
	token = strtok(program_ptr->current_line, " \n\t");
	if (token == NULL)
	{
		program_ptr->current_opcode = NULL;
		return;
	}
	program_ptr->current_opcode = token;
	if (strcmp(program_ptr->current_opcode, "push") == 0)
	{
		token = strtok(NULL, " \n\t");
		if (token == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				program_ptr->line_num);
			exit(EXIT_FAILURE);
		}
		arg = strtol(token, &endptr, 10);
		if (*endptr != '\0' || token == endptr)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				program_ptr->line_num);
			exit(EXIT_FAILURE);
		}
		program_ptr->current_arg = (int)arg;
	}
}

/**
 * execute_opcode - executes the current opcode
 * @program_ptr: pointer to the monty_program_t struct
 * Description: this function checks the current opcode and executes the
 * corresponding function. If the opcode is NULL (indicating an empty line or
 * just whitespace), or if the opcode is unknown, it handles these cases
 * appropriately, including exiting the program with an error message if
 * an unknown instruction is encountered.
 */
void execute_opcode(monty_program_t *program_ptr)
{
	if (program_ptr->current_opcode == NULL)
		return;
	if (strcmp(program_ptr->current_opcode, "push") == 0)
		push_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pall") == 0)
		pall_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pint") == 0)
		pint_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pop") == 0)
		pop_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "swap") == 0)
		swap_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "add") == 0)
		add_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "nop") == 0)
		nop_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "sub") == 0)
		sub_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "div") == 0)
		div_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "mul") == 0)
		mul_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "mod") == 0)
		mod_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pchar") == 0)
		pchar_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pstr") == 0)
		pstr_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "rotl") == 0)
		rotl_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "rotr") == 0)
		rotr_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "stack") == 0)
		stack_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "queue") == 0)
		queue_opcode(program_ptr);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			program_ptr->line_num, program_ptr->current_opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 *
 * Description: this function iterates through  stack and frees
 * each element. the function continues until it traversed
 * and freed the entire stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
