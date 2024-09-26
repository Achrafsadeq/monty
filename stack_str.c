#include "monty.h"
/**
 * print_character - Prints the ASCII character corresponding to the value
 * at the top of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function retrieves the value from the top of the stack, checks if
 * it's a valid ASCII value (0-127), and prints the corresponding character.
 * If the stack is empty or the value is out of range, it reports an error.
 */
void print_character(stack_t **stack, unsigned int line_number)
{
	int ASCII;

	if (stack == NULL || *stack == NULL)
		string_error(11, line_number);

	ASCII = (*stack)->n;
	if (ASCII < 0 || ASCII > 127)
		string_error(10, line_number);
	printf("%c\n", ASCII);
}

/**
 * print_string - Prints a string from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: The line number of the opcode (unused).
 *
 * This function iterates through the stack and prints characters
 * corresponding to the values stored in each node until it encounters
 * a value that is not a valid ASCII character (<= 0 or > 127).
 * If the stack is empty, it simply prints a new line.
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ASCII;
	stack_t *current_node;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	current_node = *stack;
	while (current_node != NULL)
	{
		ASCII = current_node->n;
		if (ASCII <= 0 || ASCII > 127)
			break;
		printf("%c", ASCII);
		current_node = current_node->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the top element of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: The line number of the opcode (unused).
 *
 * This function moves the top element of the stack to the bottom,
 * adjusting the pointers accordingly. If the stack is empty or
 * has only one element, no action is taken.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current_node = *stack;
	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	(*stack)->prev = current_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last element of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: The line number of the opcode (unused).
 *
 * This function moves the last element of the stack to the top,
 * adjusting the pointers accordingly. If the stack is empty or
 * has only one element, no action is taken.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current_node = *stack;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	current_node->prev->next = NULL;
	current_node->prev = NULL;
	(*stack)->prev = current_node;
	(*stack) = current_node;
}
