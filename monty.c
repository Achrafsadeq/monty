#include "monty.h"

static stack_t *head = NULL; /* Head is now static */

/**
 * main - Entry point of the Monty bytecode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * This function checks for the correct number of arguments and
 * opens the specified Monty bytecode file. It also frees any
 * allocated nodes before exiting.
 *
 * Return: Always returns 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * allocate_node - Creates a new stack node.
 * @n: The integer value to be stored in the node.
 *
 * This function allocates memory for a new stack node, initializes
 * its fields, and returns a pointer to the newly created node.
 *
 * Return: A pointer to the new node on success, or NULL on failure.
 */
stack_t *allocate_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 *
 * This function traverses the stack and frees each node.
 * If the stack is empty, the function returns immediately.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * enqueue_node - Adds a new node to the end of the queue.
 * @new_node: Double pointer to the new node to be added.
 * @ln: The line number of the opcode (unused).
 *
 * This function adds a new node to the end of the queue. If the
 * queue is empty, the new node becomes the head of the queue.
 *
 * Return: This function does not return a value.
 */
void enqueue_node(stack_t **new_node, __attribute__((unused)) unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
