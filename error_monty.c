#include "monty.h"

/**
 * error - Prints appropriate error messages based on the error code.
 * @error_code: The code indicating the type of error that occurred.
 *
 * Error Codes:
 * (1) The user does not provide any file or provides more than one file.
 * (2) The specified file cannot be opened or read.
 * (3) The file contains an invalid instruction.
 * (4) Memory allocation fails.
 * (5) The parameter passed to the instruction "push" is not an integer.
 */
void error(int error_code, ...)
{
	va_list arguments;
	char *pointer;
	int l_number;

	va_start(arguments, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arguments, char *));
			break;
		case 3:
			l_number = va_arg(arguments, int);
			pointer = va_arg(arguments, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_number, pointer);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arguments, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * extended_error - Handles additional error cases.
 * @error_code: The code indicating the type of error that occurred.
 *
 * Error Codes:
 * (6) The stack is empty when attempting to print the top element.
 * (7) The stack is empty when attempting to pop an element.
 * (8) The stack is too short for the requested operation.
 * (9) Division by zero encountered in operations.
 */
void extended_error(int error_code, ...)
{
	va_list arguments;
	char *pointer;
	int l_number;

	va_start(arguments, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arguments, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arguments, int));
			break;
		case 8:
			l_number = va_arg(arguments, unsigned int);
			pointer = va_arg(arguments, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_number, pointer);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arguments, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - Handles errors related to string operations.
 * @error_code: The code indicating the type of error that occurred.
 *
 * Error Codes:
 * (10) The value inside a node is outside the ASCII range.
 * (11) The stack is empty when attempting to print a character.
 */
void string_error(int error_code, ...)
{
	va_list arguments;
	int l_number;

	va_start(arguments, error_code);
	l_number = va_arg(arguments, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
