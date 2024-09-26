#include "monty.h"
/**
 * multiply_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function multiplies the top two elements of the stack and replaces
 * the second top element with the result. If there are fewer than two
 * elements, it reports an error.
 */
void multiply_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extended_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modulate_nodes - Computes the remainder of the division of the second top
 * element by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function computes the remainder of the division of the second
 * top element by the top element and replaces the second top element
 * with the result. If the top element is zero or if there are fewer
 * than two elements, it reports an error.
 */
void modulate_nodes(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extended_error(8, line_number, "mod");

	if ((*stack)->n == 0)
		extended_error(9, line_number);

	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
