#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *param_l, *tmp_l, *track_i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (track_i = (*list)->next; track_i != NULL; track_i = tmp_l)
	{
		tmp_l = track_i->next;
		param_l = track_i->prev;
		while (param_l != NULL && track_i->n < param_l->n)
		{
			swap_nodes(list, &param_l, track_i);
			print_list((const listint_t *)*list);
		}
	}
}
