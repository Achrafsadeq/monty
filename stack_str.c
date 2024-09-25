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
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_error(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_error(10, line_number);
	printf("%c\n", ascii);
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
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotate_left - Rotates the top element of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: The line number of the opcode (unused).
 *
 * This function moves the top element of the stack to the bottom,
 * adjusting the pointers accordingly. If the stack is empty or
 * has only one element, no action is taken.
 */
void rotate_left(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotate_right - Rotates the last element of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: The line number of the opcode (unused).
 *
 * This function moves the last element of the stack to the top,
 * adjusting the pointers accordingly. If the stack is empty or
 * has only one element, no action is taken.
 */
void rotate_right(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
