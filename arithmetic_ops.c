#include "monty.h"

/**
 * do_nothing - Performs no operation.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function does nothing and is used as a placeholder for
 * instructions that require an operation but no action is needed.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_elements - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function swaps the top two elements of the stack. If there
 * are fewer than two elements, it reports an error.
 */
void swap_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extended_error(8, line_number, "swap");

	aux = (*stack)->next;
	(*stack)->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = *stack;
	aux->next = *stack;
	(*stack)->prev = aux;
	aux->prev = NULL;
	*stack = aux;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function adds the top two elements of the stack and replaces
 * the second element with the result. If there are fewer than two
 * elements, it reports an error.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extended_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subtract_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function subtracts the top element from the second top element
 * and replaces the second top element with the result. If there are
 * fewer than two elements, it reports an error.
 */
void subtract_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extended_error(8, line_number, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide_nodes - Divides the second top element by the top
 * element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: The line number of the opcode for error reporting.
 *
 * This function divides the second top element by the top element and
 * replaces the second top element with the result. If the top element
 * is zero, it reports an error. If there are fewer than two elements,
 * it also reports an error.
 */
void divide_nodes(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		extended_error(8, line_number, "div");

	if ((*stack)->n == 0)
		extended_error(9, line_number);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
