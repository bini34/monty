# Monty Project

## Introduction

Welcome to the Monty project! This project focuses on implementing a scripting language interpreter for Monty ByteCodes files. The language relies on a unique stack with specific instructions to manipulate it.

## Project Details

- **Project Title:** Monty ByteCode Interpreter
- **Author:** Julien Barbier
- **Weight:** 2

## Team Information

- **Team Members:**
  - Numerous Oriabure
  - Biniyam BEYENE

## Project Timeline

- Project Start: November 14, 2023, 6:00 AM
- Project Deadline: November 17, 2023, 6:00 AM
- Checker Release: November 15, 2023, 12:00 AM
- Auto Review at Deadline

## Learning Objectives

By the end of this project, you are expected to understand:

- The meaning of LIFO and FIFO
- Stack and queue data structures and their implementations
- Use cases for stacks and queues
- Proper use of global variables
- Compilation and output requirements
- Code structure and style adhering to the Betty style
- Memory management using malloc and free
- Monty ByteCode language specifications

## Resources

Before diving into the project, make sure to review the following:

- [Google](https://www.google.com/webhp?q=stack%20and%20queue)
- [How do I use extern to share variables between source files in C?](https://www.google.com/webhp?q=stack%20and%20queue) (Google search recommended)
- Stacks and Queues in C]
- Stack operations
- Queue operations

## Requirements

### General

- **Allowed Editors:** vi, vim, emacs
- **Compilation:** Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic -std=c89
- All files should end with a new line
- README.md file is mandatory
- Code should follow the Betty style
- Maximum of one global variable allowed
- No more than 5 functions per file
- Use of C standard library allowed
- Prototypes of functions should be included in a header file named `monty.h`
- All header files should be include guarded

### GitHub

- One project repository per group
- Avoid cloning/forking a project repository with the same name before the second deadline to prevent a 0% score

## Data Structures

Use the following data structures for this project:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

Compile your code using the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

- Output should be printed on stdout
- Error messages should be printed on stderr

## Tasks

### 0. push, pall (mandatory)

Implement the `push` and `pall` opcodes. Refer to the project specifications for detailed instructions.

```bash
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
$ ./monty bytecodes/00.m
3
2
1
```

**Repo:**
[GitHub Repository: monty](#)

### 1. pint (mandatory)

Implement the `pint` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m 
1
2
3
```

**Repo:**
[GitHub Repository: monty](#)

### 2. pop (mandatory)

Implement the `pop` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ./monty bytecodes/07.m 
3
2
1
2
1
1
```

**Repo:**
[GitHub Repository: monty](#)

### 3. swap (mandatory)

Implement the `swap` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
$ ./monty bytecodes/09.m 
3
2
1
2
3
1
```

**Repo:**
[GitHub Repository: monty](#)

### 4. add (mandatory)

Implement the `add` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall
$ ./monty bytecodes/12.m 
3
2
1
5
1
```

**Repo:**
[GitHub Repository: monty](#)

### 5. nop (mandatory)

Implement the `nop` opcode. Refer to the project specifications for detailed instructions.

**Repo:**
[GitHub Repository: monty](#)

### 6. sub (advanced)

Implement the `sub` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
$ ./monty bytecodes/19.m 
7
2
1
```

**Repo:**
[GitHub Repository: monty](#)

### 7. div (advanced)

Implement the `div` opcode. Refer to the project specifications for detailed instructions.

**Repo:**
[GitHub Repository: monty](#)

### 8. mul (advanced)

Implement the `mul` opcode. Refer to the project specifications for detailed instructions.

**Repo:**
[GitHub Repository: monty](#)

### 9. mod (advanced)

Implement the `mod` opcode. Refer to the project specifications for detailed instructions.

**Repo:**
[GitHub Repository: monty](#)

### 10. comments (advanced)

Implement support for comments in the Monty language. Refer to the project specifications for detailed instructions.

**Repo:**
[GitHub Repository: monty](#)

### 11. pchar (advanced)

Implement the `pchar` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/28.m 
push 72
pchar
$ ./monty bytecodes/

28.m 
H
```

**Repo:**
[GitHub Repository: monty](#)

### 12. pstr (advanced)

Implement the `pstr` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
$ ./monty bytecodes/31.m 
School
```

**Repo:**
[GitHub Repository: monty](#)

### 13. rotl (advanced)

Implement the `rotl` opcode. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
```

**Repo:**
[GitHub Repository: monty](#)

### 14. rotr (advanced)

Implement the `rotr` opcode. Refer to the project specifications for detailed instructions.

**Repo:**
[GitHub Repository: monty](#)

### 15. stack, queue (advanced)

Implement the `stack` and `queue` opcodes. Refer to the project specifications for detailed instructions.

```bash
$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
```

**Repo:**
[GitHub Repository: monty](#)

### 16. Brainf*ck (advanced)

Write a Brainf*ck script that prints "School," followed by a new line. Place your Brainf*ck files inside the `bf` subdirectory.

```bash
$ bf 1000-school.bf 
School
```

**Repo:**
[GitHub Repository: monty](#)
[Directory: bf](#)
[File: 1000-school.bf](#)

### 17. Add two digits (advanced)

Add two digits given by the user. Read the two digits from stdin, add them, and print the result.

```bash
$ bf ./1001-add.bf
81
9
```

**Repo:**
[GitHub Repository: monty](#)
[Directory: bf](#)
[File: 1001-add.bf](#)

### 18. Multiplication (advanced)

Multiply two digits given by the user. Read the two digits from stdin, multiply them, and print the result.

```bash
$ bf 1002-mul.bf
24
8
```

**Repo:**
[GitHub Repository: monty](#)
[Directory: bf](#)
[File: 1002-mul.bf](#)

### 19. Multiplication level up (advanced)

Multiply two digits given by the user. Read the two digits from stdin, multiply them, and print the result, followed by a new line.

```bash
$ bf 1003-mul.bf 
77
49
```

**Repo:**
[GitHub Repository: monty](#)
[Directory: bf](#)
[File: 1003-mul.bf](#)

## Copyright

© 2023 ALX, All rights reserved.
