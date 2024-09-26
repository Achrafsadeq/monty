#include "monty.h"

/* 
 * push_stack - Adds a new node to the top of the stack.
 * @new_node: Pointer to the new node to be added.
 * @ln: The line number of the opcode for error reporting.
 *
 * This function adds a node to the top of the stack. If the stack is
 * empty, the new node becomes the head of the stack.
 */
void push_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *current_node; /* Pointer to the current top node */

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE); /* Exit if new_node is NULL */
	if (head == NULL)
	{
		head = *new_node; /* Set head to new_node if stack is empty */
		return;
	}
	current_node = head; /* Store the current top node */
	head = *new_node; /* Update head to new_node */
	head->next = current_node; /* Set new_node's next to the current top */
	current_node->prev = head; /* Update current node's previous to new_node */
}

/* 
 * display_stack - Prints all the elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function iterates through the stack and prints each element
 * from top to bottom.
 */
void display_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node; /* Pointer to the current node being printed */

	(void) line_number; /* Unused variable for error reporting */
	if (stack == NULL)
		exit(EXIT_FAILURE); /* Exit if stack is NULL */
	current_node = *stack; /* Get the top node of the stack */
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n); /* Print current node's value */
		current_node = current_node->next; /* Move to the next node */
	}
}

/* 
 * remove_top - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function removes the top node from the stack and frees its memory.
 * If the stack is empty, it reports an error.
 */
void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node; /* Pointer to the current top node */

	if (stack == NULL || *stack == NULL)
		extended_error(7, line_number); /* Report error if stack is empty */

	current_node = *stack; /* Store the current top node */
	*stack = current_node->next; /* Update the top node to the next one */
	if (*stack != NULL)
		(*stack)->prev = NULL; /* Update the new top node's previous pointer */
	free(current_node); /* Free the memory of the old top node */
}

/* 
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
		extended_error(6, line_number); /* Report error if stack is empty */
	printf("%d\n", (*stack)->n); /* Print the value of the top node */
}
