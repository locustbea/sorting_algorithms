#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 *
 * Description: sorting an array of integers in ascending order using
 * selection sort algorithm
 *
 * @array: The array of integer to sort
 * @size: size of the array of integer
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k, pos;
	int tmp_data;

	if (array == NULL)
		return;
	if (size <= 1)
		return;
	for (k = 1; k < size; k++)
	{
		if (array[k - 1] > array[k])
			break;
	}
	if (k == size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tmp_data = array[i];
		for (j = i; j < size; j++)
		{
			if (tmp_data > array[j])
			{
				tmp_data = array[j];
				pos = j;
			}
		}
		if (array[i] != tmp_data)
		{
			array[pos] = array[i];
			array[i] = tmp_data;
			print_array(array, size);
		}
	}
}
