# 0x19. C - Stacks, Queues - LIFO, FIFO

## Description

This project focuses on implementing an interpreter for Monty ByteCodes, a language that relies on stack operations (LIFO) and queue operations (FIFO). You will create a stack-based virtual machine that can execute byte code files written in the Monty language. The key objective is to understand and manipulate data structures such as stacks and queues using opcodes (e.g., `push`, `pop`, `swap`).

## Requirements

| Category            | Details                                                              |
|---------------------|----------------------------------------------------------------------|
| **Editors**          | vi, vim, emacs                                                       |
| **Compiler**         | Ubuntu 20.04 LTS using gcc                                           |
| **File Endings**     | All files should end with a new line                                 |
| **README**           | A README.md file at the root of the project folder is mandatory       |
| **Coding Style**     | Code should follow the Betty style                                   |
| **Global Variables** | A maximum of one global variable is allowed                          |
| **Functions per File**| No more than 5 functions per file                                   |
| **Allowed Libraries**| Only the C standard library                                          |
| **Header File**      | All prototypes must be included in the header file `monty.h`         |
| **Include Guards**   | Header files must be include guarded                                 |
| **Bash Scripts**     | Bash scripts should start with `#!/bin/bash`                         |

### Coding Guidelines
- The prototypes of all functions should be included in the header file `monty.h`.
- Your code will be compiled with the flags `-Wall -Werror -Wextra -pedantic -std=c89`.
- Each opcode in the Monty language should be implemented according to its usage.
- Handle errors and edge cases as specified in the tasks.
- Memory allocation errors should be handled, and you should use `malloc` and `free`.

## Tasks

| Task # | Description                                                                 |  
|--------|-----------------------------------------------------------------------------|
| **0**  | Implement the `push` and `pall` opcodes in the Monty language.              |  
| **1**  | Implement the `pint` opcode that prints the value at the top of the stack.  |  
| **2**  | Implement the `pop` opcode that removes the top element of the stack.       |  
| **3**  | Implement the `swap` opcode that swaps the top two elements of the stack.   |  
| **4**  | Implement the `add` opcode that adds the top two elements of the stack.     |  
| **5**  | Implement the `nop` opcode that doesn’t perform any operation.              | 

### Advanced Tasks

| Task # | Description                                                                 | 
|--------|-----------------------------------------------------------------------------|
| **6**  | Implement the `sub` opcode that subtracts the top element from the second.  |  
| **7**  | Implement the `mul`, `div`, and `mod` opcodes for multiplication, division, and modulus. |  
| **8**  | Implement the `pchar` opcode that prints the char at the top of the stack.  | 
| **9**  | Implement the `pstr` opcode that prints the string starting from the top of the stack. |  
| **10** | Treat lines starting with `#` as comments and ignore them.                  | 
| **11** | Implement the `pchar` opcode that prints the ASCII character at the top of the stack. |  
| **12** | Implement the `pstr` opcode that prints a string starting from the top of the stack. |  
| **13** | Implement the `rotl` opcode that rotates the stack to the top.              |  
| **14** | Implement the `rotr` opcode that rotates the stack to the bottom.           |  
| **15** | Implement the `stack` and `queue` opcodes to switch between stack (LIFO) and queue (FIFO) modes. |
| **16** | Write a Brainf*ck script to print `School`.                                 |  
| **17** | Write a Brainf*ck script to add two digits provided by the user.            |  
| **18** | Write a Brainf*ck script to multiply two digits provided by the user.       |  
| **19** | Write a Brainf*ck script to multiply two digits provided by the user and print the result followed by a newline. | 

## Learning Objectives

By the end of this project, you will be able to:

- Understand stacks and queues as data structures.
- Implement basic stack and queue operations.
- Interpret Monty bytecode and create a virtual machine that processes it.
- Work with error handling and edge cases in stack-based languages.
- Manage memory dynamically and ensure proper error handling.

## Mission Director

This project is supervised by Holberton School and the ALX Software Engineering Program.

## Developer

**Codename:** Achraf Sadeq & Elhoucine Smaili

## Acknowledgments

Holberton School, in collaboration with the ALX Software Engineering Program, developed this project for educational purposes.
