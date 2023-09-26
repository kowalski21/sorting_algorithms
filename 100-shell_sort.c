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
 * shell_sort - Sort an int array using shell algo
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t skip, outer_track, counter;

	if (array == NULL || size < 2)
		return;

	for (skip = 1; skip < (size / 3);)
		skip = skip * 3 + 1;

	for (; skip >= 1; skip /= 3)
	{
		for (outer_track = skip; outer_track < size; outer_track++)
		{
			counter = outer_track;
			while (counter >= skip && array[counter - skip] > array[counter])
			{
				swap_arr_int(array + counter, array + (counter - skip));
				counter -= skip;
			}
		}
		print_array(array, size);
	}
}
