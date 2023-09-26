#include "sort.h"

/**
 * swap_array_ints - Swap two integers in an array.
 * @ptr_a: The first integer to swap.
 * @ptr_b: The second integer to swap.
 */
void swap_array_ints(int *ptr_a, int *ptr_b)
{
	int tmp;

	tmp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = tmp;
}


/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n_node: A pointer to the first node to swap.
 * @t_node: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n_node, listint_t *t_node)
{
	(*n_node)->next = t_node->next;
	if (t_node->next != NULL)
		t_node->next->prev = *n_node;
	t_node->prev = (*n_node)->prev;
	t_node->next = *n_node;
	if ((*n_node)->prev != NULL)
		(*n_node)->prev->next = t_node;
	else
		*h = t_node;
	(*n_node)->prev = t_node;
	*n_node = t_node->prev;
}
