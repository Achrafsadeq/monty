#include "monty.h"

/**
 * push_stack - Adds a new node to the top of the stack.
 * @new_node: Pointer to the new node to be added.
 * @ln: The line number of the opcode for error reporting.
 *
 * This function adds a node to the top of the stack. If the stack is
 * empty, the new node becomes the head of the stack.
 */
void push_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * display_stack - Prints all the elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function iterates through the stack and prints each element
 * from top to bottom.
 */
void display_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * remove_top - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function removes the top node from the stack and frees its memory.
 * If the stack is empty, it reports an error.
 */
void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		extended_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top_node - Prints the value of the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function prints the value of the top node of the stack.
 * If the stack is empty, it reports an error.
 */
void print_top_node(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		extended_error(6, line_number);
	printf("%d\n", (*stack)->n);
}
