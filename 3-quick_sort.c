#include "sort.h"



/**
 * swap_arr_int - Swap two integers in an arr.
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
 * lomuto_partition - implement lomuto partition
 * @arr: The arr of integers.
 * @size: The size of the arr.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *arr, size_t size, int left, int right)
{
	int *tracker, above, below;

	tracker = arr + right;
	for (above = below = left; below < right; below++)
	{
		if (arr[below] < *tracker)
		{
			if (above < below)
			{
				swap_arr_int(arr + below, arr + above);
				print_array(arr, size);
			}
			above++;
		}
	}

	if (arr[above] > *tracker)
	{
		swap_arr_int(arr + above, tracker);
		print_array(arr, size);
	}

	return (above);
}

/**
 * custom_sort - sort using partition scheme
 * @arr: An arr of integers to sort.
 * @size: The size of the arr.
 * @left: The starting index of the arr partition to order.
 * @right: The ending index of the arr partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void custom_sort(int *arr, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(arr, size, left, right);
		custom_sort(arr, size, left, part - 1);
		custom_sort(arr, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an arr of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An arr of integers.
 * @size: The size of the arr.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the arr after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	custom_sort(array, size, 0, size - 1);
}
