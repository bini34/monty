#include "monty.h"
/**
 * execute_operations - Parses the file and executes the Monty operations.
 * @file: File pointer to the Monty bytecode file.
 * @stack: Double pointer to the stack.
 */
void execute_operations(FILE *file, stack_t **stack)
{
	char opcode[100];
	int value;

	while (fscanf(file, "%99s", opcode) == 1)
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
			push(stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(stack);
		else if (strcmp(opcode, "swap") == 0)
			swap(stack, __LINE__);
		else if (strcmp(opcode, "add") == 0)
			add(stack, __LINE__);
		else if (strcmp(opcode, "pchar") == 0)
			pchar(stack, __LINE__);
		else if (strcmp(opcode, "sub") == 0)
			sub(stack, __LINE__);
		else if (strcmp(opcode, "div") == 0)
			divide(stack, __LINE__);
		else if (strcmp(opcode, "mul") == 0)
			mul(stack, __LINE__);
		else if (strcmp(opcode, "mod") == 0)
			mod(stack, __LINE__);
		else if (strcmp(opcode, "nop") == 0)
		fscanf(file, "%*[^\n]");
		fgetc(file);
	}
}
/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
 	stack_t *stack;

 	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	execute_operations(file, &stack);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
