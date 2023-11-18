#include "sort.h"

/**
 * quick_sort- sorts the array of an integer
 *
 * Description: This function sorts an array of integers using
 * quick sort algorithm.
 *
 * @array: array of integers to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t k;

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
	finder(array, size, array, size);
}

/**
 * finder - finds the correct position of pivot in an array of integer
 *
 * @partial: partial of array
 * @array: array of integer to sort
 * @size: size of the partial
 * @orig_size: original size of the array to sort
 * Return: nothing
 */
void finder(int *partial, size_t size, int *array, size_t orig_size)
{
	int pivot, tmp_data;
	size_t i, j, k;

	i = 0;
	j = 0;
	k = 0;
	if (size <= 1 || orig_size <= 1)
		return;
	pivot = partial[size - 1];
	while (k <= size - 1)
	{
		if (partial[i] <= pivot && i < size - 1)
			i++;
		else
		{
			j = i;
			while (partial[j] > pivot)
				j++;
			if (i != size - 1)
			{
				tmp_data = partial[i];
				partial[i] = partial[j];
				partial[j] = tmp_data;
				print_array(array, orig_size);
			}
			if (j == size - 1)
				break;
		}
		k = i;
	}
	finder(partial, i, array, orig_size);
	partial += (i + 1);
	finder(partial, size - (i + 1), array, orig_size);
}
