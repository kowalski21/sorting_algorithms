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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t counter, arr_len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (counter = 0; counter < arr_len - 1; counter++)
		{
			if (array[counter] > array[counter + 1])
			{
				swap_arr_int(array + counter, array + counter + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		arr_len--;
	}
}
