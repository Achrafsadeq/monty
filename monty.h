#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(const char *file_name);
int manage_line_parsing(char *buffer, int line_number, int format);
void manage_file_read(FILE *);
int manage_char_count(FILE *);
void find_func(char *, char *, int, int);

stack_t *create_node(int n);
void free_nodes(void);
void display_stack(stack_t **, unsigned int);
void push_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void execute_func(op_func, char *, char *, int, int);
void print_top_node(stack_t **, unsigned int);
void remove_top(stack_t **, unsigned int);
void do_nothing(stack_t **, unsigned int);
void swap_elements(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void subtract_nodes(stack_t **, unsigned int);
void divide_nodes(stack_t **, unsigned int);
void multiply_nodes(stack_t **, unsigned int);
void modulate_nodes(stack_t **, unsigned int);
void print_character(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void error(int error_code, ...);
void extended_error(int error_code, ...);
void string_error(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
