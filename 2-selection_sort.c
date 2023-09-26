#include "sort.h"

/**
 * swap_arr_int - Swap two integers in an array.
 * @num_1: The first integer to swap.
 * @num_2: The second integer to swap.
 */
void swap_arr_int(int *num_1, int *num_2)
{
	int tmp;

	tmp = *num_1;
	*num_1 = *num_2;
	*num_2 = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_num;
	size_t outer_track, inner_track;

	if (array == NULL || size < 2)
		return;

	for (outer_track = 0; outer_track < size - 1; outer_track++)
	{
		min_num = array + outer_track;
		for (inner_track = outer_track + 1; inner_track < size; inner_track++)
			min_num = (array[inner_track] < *min_num) ? (array + inner_track) : min_num;

		if ((array + outer_track) != min_num)
		{
			swap_arr_int(array + outer_track, min_num);
			print_array(array, size);
		}
	}
}
