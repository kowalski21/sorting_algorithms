#include "sort.h"


/**
 * custom_lumoto_part - Order a subset of an array of integers according to
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
  * @array: The array of integers.
 *
 * Return: The final partition index.
 */
int custom_lumoto_part(size_t size, int left, int right, int *array)
{
	int *tracker, h_limit, l_limit;

	tracker = array + right;
	for (h_limit = l_limit = left; l_limit < right; l_limit++)
	{
		if (array[l_limit] < *tracker)
		{
			if (h_limit < l_limit)
			{
				swap_array_ints(array + l_limit, array + h_limit);
				print_array(array, size);
			}
			h_limit++;
		}
	}

	if (array[h_limit] > *tracker)
	{
		swap_array_ints(array + h_limit, tracker);
		print_array(array, size);
	}

	return (h_limit);
}



/**
 * recur_lumosort - Implement the quicksort algorithm through recursion.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * @array: An array of integers to sort.
 * Description: Uses the Lomuto partition scheme.
 */
void recur_lumosort(size_t size, int left, int right, int *array)
{
	int tracker;

	if (right - left > 0)
	{
		tracker = custom_lumoto_part(size, left, right, array);
		recur_lumosort(size, left, tracker - 1, array);
		recur_lumosort(size, tracker + 1, right, array);
	}
}
