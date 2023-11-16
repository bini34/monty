#include "monty.h"

/**
 * process_file - Reads and processes the Monty bytecode file.
 * @file: File pointer to the Monty bytecode file.
 * @stack: Double pointer to the stack.
 */
void process_file(FILE *file, stack_t **stack)
{
	char *line = NULL, *opcode, *arg;
	size_t len = 1024;
	int value, i;

	instruction_t instructions[] = {{"push", push}, {"pall", pall},
		{"swap", swap}, {"add", add}, {"pchar", pchar}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"nop", nop},
		{NULL, NULL}};
	line = (char *)malloc(len);
	if (line == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, file) != NULL)
	{
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				if (strcmp(opcode, "push") == 0)
				{
					arg = strtok(NULL, " \n\t");
					if (arg == NULL)
					{
						fprintf(stderr, "Error: %s requires an argument\n", opcode);
						fclose(file);
						free_stack(*stack);
						free(line);
						exit(EXIT_FAILURE);
					}
					value = atoi(arg);
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
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
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
