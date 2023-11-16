#include "monty.h"

/**
 * process_file - Reads and processes the Monty bytecode file.
 * @file: File pointer to the Monty bytecode file.
 * @stack: Double pointer to the stack.
 */
void process_file(FILE *file, stack_t **stack)
{
	char opcode[100];
	int value, i;

	instruction_t instructions[] = {{"push", push}, {"pall", pall},
		{"swap", swap}, {"add", add}, {"pchar", pchar}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"nop", nop},
		{NULL, NULL}};
	while (fscanf(file, "%99s", opcode) == 1)
	{
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				if (strcmp(opcode, "push") == 0)
				{
					if (fscanf(file, "%d", &value) != 1)
					{
						fprintf(stderr, "Error: usage: push integer\n");
						fclose(file);
						free_stack(*stack);
						exit(EXIT_FAILURE);
					}
					instructions[i].f(stack, value);
				}
				else
					instructions[i].f(stack, __LINE__);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", __LINE__, opcode);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		fscanf(file, "%*[^\n]");
		fgetc(file);
	}
}
/**
 * execute_file - Executes Monty operations based on the file contents.
 * @filename: Name of the Monty bytecode file.
 */
void execute_file(const char *filename)
{
	FILE *file;
	stack_t *stack;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	process_file(file, &stack);
	fclose(file);
	free_stack(stack);
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execute_file(argv[1]);
	return (EXIT_SUCCESS);
}
