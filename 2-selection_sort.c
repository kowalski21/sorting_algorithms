#include "sort.h"


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
	int *tracker;
	size_t inner_count, outer_count;

	if (array == NULL || size < 2)
		return;

	for (inner_count = 0; inner_count < size - 1; inner_count++)
	{
		tracker = array + inner_count;
		for (outer_count = inner_count + 1; outer_count < size; outer_count++)
			tracker = (array[outer_count] < *tracker) ? (array + outer_count) : tracker;

		if ((array + inner_count) != tracker)
		{
			swap_array_ints(array + inner_count, tracker);
			print_array(array, size);
		}
	}
}
