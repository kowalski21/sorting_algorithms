/*
 * File: 0-bubble_sort.c
 * Auth: Brennan D Baraban
 */

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
	size_t i, arr_len = size;
	bool checker = false;

	if (array == NULL || size < 2)
		return;

	while (checker == false)
	{
		checker = true;
		for (i = 0; i < arr_len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_arr_int(array + i, array + i + 1);
				print_array(array, size);
				checker = false;
			}
		}
		arr_len--;
	}
}
