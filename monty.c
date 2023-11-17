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
    unsigned int line_number = 0;

    while (fscanf(file, "%99s", opcode) == 1)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &value) != 1)
            {
                fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
                fclose(file);
                free_stack(*stack);
                exit(EXIT_FAILURE);
            }
            push(stack, value);
        }
        else
        {
            int i;

            instruction_t instructions[] = {
                {"pall", pall},
                {"swap", swap},
                {"add", add},
                {"pchar", pchar},
                {"sub", sub},
                {"div", divide},
                {"mul", mul},
                {"mod", mod},
                {"nop", nop},
                {NULL, NULL}};

            for (i = 0; instructions[i].opcode != NULL; i++)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(stack, line_number);
                    break;
                }
            }

            if (instructions[i].opcode == NULL)
            {
                fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
                fclose(file);
                free_stack(*stack);
                exit(EXIT_FAILURE);
            }
        }

        fscanf(file, "%*[^\n]");
        fgetc(file);

        line_number++;
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

