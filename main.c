#include "monty.h"

/**
 * main - entry point for the Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: (0) on success, exits with EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	monty_program_t program = {NULL};
	monty_program_t *program_ptr = &program;
	char line[1024];

	program_ptr->stack = NULL;
	program_ptr->line_num = 0;
	program_ptr->mode = 0;
	program_ptr->current_line = NULL;
	program_ptr->current_opcode = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	program_ptr->script_file = fopen(argv[1], "r");
	if (program_ptr->script_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), program_ptr->script_file))
	{
		program_ptr->line_num++;
		program_ptr->current_line = line;
		parse_line(program_ptr);
		execute_opcode(program_ptr);
	}
	fclose(program_ptr->script_file);
	free_stack(program_ptr->stack);

	return (0);
}
