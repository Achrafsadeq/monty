#include "monty.h"

stack_t *head = NULL; /* Head is now global */

/**
 * main - Entry point of the Monty bytecode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
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
 * create_node - Creates a new stack node.
 * @n: The integer value to be stored in the node.
 *
 * Return: A pointer to the new node on success, or NULL on failure.
 */
stack_t *create_node(int n)
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
 * add_to_queue - Adds a new node to the end of the queue.
 * @new_node: Double pointer to the new node to be added.
 * @ln: The line number of the opcode (unused).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
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
