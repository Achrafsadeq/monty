#include "monty.h"
/**
 * open_file - Opens a file for reading.
 * @file_name: The path to the file to be opened.
 */
void open_file(const char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		error(2, file_name);

	manage_file_read(fd);
	fclose(fd);
}

/**
 * manage_file_read - Reads a file line by line.
 * @fd: Pointer to the file descriptor of the opened file.
 */
void manage_file_read(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = manage_line_parsing(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * manage_line_parsing - Parses a line of input into tokens.
 * @buffer: The line from the file to be parsed.
 * @line_number: The current line number being processed.
 * @format: The storage format, indicating stack (0) or queue (1).
 *
 * Return: Returns 0 if the opcode is "stack", 1 if "queue",
 * or the current format.
 */
int manage_line_parsing(char *buffer, int line_number, int format)
{
	char *op_code, *value;
	const char *del = "\n ";

	if (buffer == NULL)
		error(4);

	op_code = strtok(buffer, del);
	if (op_code == NULL)
		return (format);
	value = strtok(NULL, del);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	find_func(op_code, value, line_number, format);
	return (format);
}

/**
 * find_func - Finds and calls the appropriate function for the opcode.
 * @opcode: The operation code to be executed.
 * @value: The argument for the opcode, if any.
 * @ln: The line number for error reporting.
 * @format: The storage format, indicating stack (0) or queue (1).
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int index;
	int flag;

	instruction_t func_list[] = {
		{"push", push_stack},
		{"pall", display_stack},
		{"pint", print_top_node},
		{"pop", remove_top},
		{"nop", do_nothing},
		{"swap", swap_elements},
		{"add", add_nodes},
		{"sub", subtract_nodes},
		{"div", divide_nodes},
		{"mul", multiply_nodes},
		{"mod", modulate_nodes},
		{"pchar", print_character},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, index = 0; func_list[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, func_list[index].opcode) == 0)
		{
			execute_func(func_list[index].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, ln, opcode);
}

/**
 * execute_func - Calls the specified function based on the opcode.
 * @func: Pointer to the function to be called.
 * @op: The opcode string to be executed.
 * @val: The argument string associated with the opcode.
 * @ln: The line number for error reporting.
 * @format: The storage format, indicating stack (0) or queue (1).
 */
void execute_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int index;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (index = 0; val[index] != '\0'; index++)
		{
			if (isdigit(val[index]) == 0)
				error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
